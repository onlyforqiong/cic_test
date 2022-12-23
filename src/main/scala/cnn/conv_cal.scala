package cnn

import chisel3._
import chisel3.stage.ChiselStage
import chisel3.experimental._
import chisel3.util._
import firrtl.PrimOps
import scala.math._
import scala.reflect.runtime.Macros
import chisel3.experimental.FixedPoint

class conv_cal(width : Int,length : Int,cnn_kernel_width:Int,channel:Int,kernel_num:Int) extends Module  with basic_macro {
    val io = IO(new Bundle {
        val data_in = Vec(channel,Input(FixedPoint(fixpoint_num_length.W,BinaryPoint_place.BP)))    
        val data_valid = Vec(channel,Input(Bool()))
        val conv_start = Vec(channel,Input(Bool()))
        val data_refresh = Input(Bool())
        val data_out = Vec(kernel_num,Output(FixedPoint(fixpoint_num_length.W,BinaryPoint_place.BP)))
        val conv_end = Vec(kernel_num,Output(Bool()))
        val const_in = Vec(kernel_num,Input(new matrix_bundle(cnn_kernel_width,cnn_kernel_width)))

        val io_out_data =Output(UInt(32.W))
    })
    class sliding_window_filter  extends Module{
        val answer = (VecInit(Seq.fill(channel)(Module(new sliding_window(width,length,cnn_kernel_width)).io)))
        val io = IO(new Bundle{
            val data_in = Vec(channel,Input(FixedPoint(fixpoint_num_length.W,BinaryPoint_place.BP)))   
            val data_valid = Vec(channel,Input(Bool())) 
            val data_refresh = Input(Bool())
            val const_in = Input(new matrix_bundle(cnn_kernel_width,cnn_kernel_width))
            val data_out =  Output(FixedPoint(fixpoint_num_length.W,BinaryPoint_place.BP))
            // val full_counter = 
        })
       
        val filter_answer = Seq.fill(channel)(RegInit(0.F(fixpoint_num_length.W,BinaryPoint_place.BP)))
        answer.zipWithIndex.foreach{case(a,index) => 
            a.const_in  := io.const_in
            a.data_in   := io.data_in(index)
            a.data_refresh := io.data_refresh
            a.data_valid  := io.data_valid(index)
            filter_answer(index) := a.data_out
        }
        
        io.data_out := List_Cal(filter_answer,fixpoint_add,0,(channel - 1))
        
  
    } 
    val multiple_cnn_kernel = VecInit(Seq.fill(kernel_num)(Module(new sliding_window_filter).io))
    multiple_cnn_kernel.zipWithIndex.foreach{case(a,index) => 
        a.data_in := io.data_in
        a.const_in := io.const_in(index)
        a.data_refresh := io.data_refresh
        a.data_valid := io.data_valid
        io.data_out(index) := a.data_out
        io.conv_end(index) := 0.asUInt
        io.io_out_data     := 0.asUInt
    }
    
    // val many_kernel_sliding_filter =  VecInit(Seq.fill(channel)((new sliding_window_filter).answer))
    // // sliding_window_filter.zipWithIndex.foreach{case(a,index) => 
    // //     val filter_answer = Seq.fill(channel)(RegInit(0.F(fixpoint_num_length.W,BinaryPoint_place.BP)))
    // //     a.zipWithIndex.foreach{case(b,index2) =>
    // //         b.const_in := io.const_in(index)
    // //         b.data_in  := io.data_in(index2)
    // //         b.data_valid := io.data_valid(index2)
    // //         b.data_refresh := io.data_refresh
    // //         filter_answer(index2) := b.data_out
    // //         // filter_answer.++:(Seq(b.data_out))
    // //     }
    // //     io.data_out := List_Cal(filter_answer,fixpoint_add,0,(channel - 1))
    // // }


}

object conv_cal_test extends App{
    (new ChiselStage).emitVerilog(new conv_cal(28,28,3,1,10))
}

