package chisel_function_test


import chisel3._
import chisel3.stage._
import chisel3.util._

class Myemp(length: Int) extends Module {
  val io = IO(new Bundle {
   val in = Input(UInt(8.W))
   val valid = Input(Bool())
   val out = Output(UInt(8.W))
   val consts = Input(Vec(length, UInt(8.W)))
  })
  val taps = Seq(io.in) ++ Seq.fill(length - 1)(RegInit(0.U(8.W)))
  taps.zip(taps.tail).foreach { case (a, b) => when (io.valid) { b := a } }
  io.out := taps.zip(io.consts).map { case (a, b) => a * b }.reduce(_ + _)
 }