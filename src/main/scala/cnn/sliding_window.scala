package cnn

import chisel3._
import chisel3.stage.ChiselStage
import chisel3.experimental._
import chisel3.util._
import firrtl.PrimOps
import scala.math._
import scala.reflect.runtime.Macros
import chisel3.experimental.FixedPoint
//先实现
class sliding_window(width:Int, height:Int , cnn_kernel_width :Int,padding_num:Int = 0)extends Module with basic_macro {
    val slid_windows_ = log2Up(cnn_kernel_width * cnn_kernel_width)
    val io = IO(new Bundle { 
        val data_in    = Input(FixedPoint(fixpoint_num_length.W,BinaryPoint_place.BP))
        val const_in   = Input(new matrix_bundle(cnn_kernel_width,cnn_kernel_width))
        val data_valid = Input(Bool())

        val data_refresh = Input(Bool())
        val data_out   = Output(FixedPoint(fixpoint_num_length.W,BinaryPoint_place.BP))
        val data_out_valid = Output(Bool())
        val sliding_end = Output(Bool())
        // val full_counter = log2Up(const_in.matrix_port.length) + 1 
    })
    val data_shift = Seq.fill((cnn_kernel_width - 1) * width  + cnn_kernel_width)(RegInit(0.F(fixpoint_num_length.W,BinaryPoint_place.BP)))
    data_shift.zipWithIndex.foreach{case((a),index) => 
        when(io.data_valid) {
            data_shift(index)
        }.otherwise{
            if(index == 0) {
                data_shift( index ) := io.data_in
            }else {
                data_shift(index) := data_shift(index - 1)
            }
        }
    }
    val full_counter = log2Up(io.const_in.matrix_port.length) + 1 

    val slid_windows_port = Module(new matrix_bundle_cross_bar(cnn_kernel_width ,cnn_kernel_width))
    slid_windows_port.io.matrix_input.matrix_port.zipWithIndex.foreach{case(a,index) =>
        slid_windows_port.io.matrix_input.matrix_port(index) := data_shift((index/cnn_kernel_width) * width + index%cnn_kernel_width)
    }
    io.data_out := Matrix_Mul(slid_windows_port.io.matrix_output,io.const_in)
    val (counter_a,counter_b) = Counter(io.data_valid,(width * height + full_counter))
    io.sliding_end := counter_b
    // val data_out_valid = ShiftRegister(io.data_valid,((cnn_kernel_width - 1) * width  + cnn_kernel_width + full_counter))
    io.data_out_valid := ShiftRegister(io.data_valid,((cnn_kernel_width - 1) * width  + cnn_kernel_width + full_counter))
}

object sliding_window_test extends App{
    (new ChiselStage).emitVerilog(new sliding_window(28,28,3))
}

