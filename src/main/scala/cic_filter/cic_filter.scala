package cic_filter

import chisel3._
import chisel3.stage.ChiselStage
import chisel3.experimental._
import chisel3.util._
import firrtl.PrimOps
import scala.math._
import scala.reflect.runtime.Macros
import chisel3.experimental.FixedPoint

class cic_filter_top(Bin:Int,N:Int, R:Int,M:Int ) extends RawModule    {
    val clk = IO(Input(Bool())).suggestName("clk")
    val resetn = IO(Input(Bool())).suggestName("reset_n")
    val Bout = Bin + N*log2Up(R * M)
    // val io = IO(new Bundle { 
    val data_in  = IO(Input(UInt(Bin.W)))
    val data_out = IO(Output(UInt(Bout.W)))
    val data_en  = IO(Input(Bool()))
        // val matrix_input  = Input(new matrix_bundle(3,3))
        // val matrix_const  = Input(new matrix_bundle(3,3))
        // val matrix_output = Output(FixedPoint(fixpoint_num_length.W,BinaryPoint_place.BP))
    // })
    withClockAndReset(clk.asClock,(~resetn).asAsyncReset) {

        // val 
        val (counter_a,counter_b) = Counter(data_en,(R - 1))
        // 积分器部分
        val sum = Seq.fill(N)(RegInit(0.U(Bout.W)))
        // val sum_next = Wire(Vec(N,UInt(Bout.W)))
        // for()
        sum.zipWithIndex.foreach{case(a,index) =>
            // sum(index) := sum_next(index)
            if(index == 0 ) {
                sum(index) := sum(index) + data_in
            }else{
                sum(index) := sum(index - 1) + sum(index)
            }
        }
        val sum_out = sum(N - 1) + sum(N - 2)
        
        //梳状滤波器
        withClockAndReset(counter_b.asClock,(~resetn).asAsyncReset) {
            val sub_next = Wire(Vec(N,UInt(Bout.W)))
            val sub = Seq.fill(N)(RegInit(0.U(Bout.W)))
            val sub_out = RegInit(0.U(Bout.W))
            sub.zipWithIndex.foreach{case(a,index) =>
                
                if(index == 0 ) {
                    sub_next(index) := sum_out - sub(index)
                    sub(index) := sum_out 
                }else{
                    sub_next(index) := sub_next(index - 1) - sub(index)
                    sub(index) := sub_next(index - 1)
                }
            }
            sub_out := sub_next(N - 1)
            data_out := sub_out
        }
       
        // e 
    // matrix_output := Matrix_Mul(matrix_input,matrix_const)
    }   
    
}


object cic_filter_top_test extends App{
    (new ChiselStage).emitVerilog(new cic_filter_top(1,3,64,1))
}
