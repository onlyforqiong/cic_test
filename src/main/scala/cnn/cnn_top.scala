package cnn

import chisel3._
import chisel3.stage._
import chisel3.util._
import chisel3.experimental.FixedPoint

class cnn_top extends Module  with basic_macro {
        
    val io = IO(new Bundle { 
        val matrix_input  = Input(new matrix_bundle(3,3))
        val matrix_const  = Input(new matrix_bundle(3,3))
        val matrix_output = Output(FixedPoint(fixpoint_num_length.W,BinaryPoint_place.BP))
    })
    io.matrix_output := Matrix_Mul(io.matrix_input,io.matrix_const)
    
}

// object cnn_top_test extends App{
//     (new ChiselStage).emitVerilog(new cnn_top)
// }

