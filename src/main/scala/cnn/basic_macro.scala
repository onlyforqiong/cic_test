package cnn

import chisel3._
import chisel3.stage.ChiselStage
import chisel3.experimental._
import chisel3.util._
import firrtl.PrimOps
import scala.math._
import scala.reflect.runtime.Macros
import chisel3.experimental.FixedPoint



trait basic_macro  {
    val data_interface_length = 32
    val fixpoint_num_length = 16
    val BinaryPoint_place = 8
    class matrix_bundle(width:Int , length:Int) extends Bundle {
        val matrix_port = Vec(width * length,(FixedPoint(fixpoint_num_length.W,BinaryPoint_place.BP)))
        //                                                                                         .toSeq
    }

    def fixpoint_relu(a :FixedPoint) : FixedPoint = {
        Mux(a < 0.F(fixpoint_num_length.W,BinaryPoint_place.BP),0.F(fixpoint_num_length.W,BinaryPoint_place.BP),a)
    }
    def List_Cal(a:Seq[FixedPoint],op:(FixedPoint,FixedPoint) => FixedPoint,start:Int,end:Int) : (FixedPoint) = {
        if(start == end) {
            (RegNext(a(start)))
            
        }else if(start == (end - 1)) {
            (RegNext(op(a(start),a(end))))
        }else{
            RegNext(op(List_Cal(a,op,start,((end + start)/ 2 - 1)) , List_Cal(a,op,(start + end)/2,end)))
        }
    }

    val fixpoint_add  = (x:FixedPoint , y:FixedPoint) => x + y
    val fixpoint_mul  = (x:FixedPoint , y:FixedPoint) => x * y

    def Matrix_Mul(data:matrix_bundle,const : matrix_bundle) : FixedPoint = {
        val mul_data_reg  = Seq.fill(const.matrix_port.length)(RegInit(0.F(fixpoint_num_length.W,BinaryPoint_place.BP)))
        data.matrix_port.zip(const.matrix_port).zipWithIndex.foreach{case((a,b),index) =>
            mul_data_reg(index) := a * b//0.F(fixpoint_num_length.W,BinaryPoint_place.BP)
        }
        // val 
        List_Cal(mul_data_reg,fixpoint_add,0,mul_data_reg.length - 1)
    }

    def Matrix_Add(data:matrix_bundle,const : matrix_bundle) : FixedPoint = {
        val mul_data_reg  = Seq.fill(const.matrix_port.length)(RegInit(0.F(fixpoint_num_length.W,BinaryPoint_place.BP)))
        data.matrix_port.zip(const.matrix_port).zipWithIndex.foreach{case((a,b),index) =>
            mul_data_reg(index) := a + b//0.F(fixpoint_num_length.W,BinaryPoint_place.BP)
        }
        // val 
        List_Cal(mul_data_reg,fixpoint_add,0,mul_data_reg.length - 1)
    }

    class matrix_bundle_cross_bar(width:Int , length:Int) extends Module {
        val io = IO(new Bundle{
            val matrix_input  = Input(new matrix_bundle(width,length))
            val matrix_output  = Output(new matrix_bundle(width,length))
        })
        io.matrix_output := io.matrix_input
    }
  
}


