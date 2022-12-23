// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vconv_cal.h for the primary calling header

#include "verilated.h"

#include "Vconv_cal__Syms.h"
#include "Vconv_cal___024root.h"

void Vconv_cal___024root___ctor_var_reset(Vconv_cal___024root* vlSelf);

Vconv_cal___024root::Vconv_cal___024root(Vconv_cal__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vconv_cal___024root___ctor_var_reset(this);
}

void Vconv_cal___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vconv_cal___024root::~Vconv_cal___024root() {
}
