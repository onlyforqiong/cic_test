// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vconv_cal.h"
#include "Vconv_cal__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vconv_cal::Vconv_cal(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vconv_cal__Syms(contextp(), _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , io_data_valid_0{vlSymsp->TOP.io_data_valid_0}
    , io_conv_start_0{vlSymsp->TOP.io_conv_start_0}
    , io_data_refresh{vlSymsp->TOP.io_data_refresh}
    , io_conv_end_0{vlSymsp->TOP.io_conv_end_0}
    , io_conv_end_1{vlSymsp->TOP.io_conv_end_1}
    , io_conv_end_2{vlSymsp->TOP.io_conv_end_2}
    , io_conv_end_3{vlSymsp->TOP.io_conv_end_3}
    , io_conv_end_4{vlSymsp->TOP.io_conv_end_4}
    , io_conv_end_5{vlSymsp->TOP.io_conv_end_5}
    , io_conv_end_6{vlSymsp->TOP.io_conv_end_6}
    , io_conv_end_7{vlSymsp->TOP.io_conv_end_7}
    , io_conv_end_8{vlSymsp->TOP.io_conv_end_8}
    , io_conv_end_9{vlSymsp->TOP.io_conv_end_9}
    , io_data_in_0{vlSymsp->TOP.io_data_in_0}
    , io_data_out_0{vlSymsp->TOP.io_data_out_0}
    , io_data_out_1{vlSymsp->TOP.io_data_out_1}
    , io_data_out_2{vlSymsp->TOP.io_data_out_2}
    , io_data_out_3{vlSymsp->TOP.io_data_out_3}
    , io_data_out_4{vlSymsp->TOP.io_data_out_4}
    , io_data_out_5{vlSymsp->TOP.io_data_out_5}
    , io_data_out_6{vlSymsp->TOP.io_data_out_6}
    , io_data_out_7{vlSymsp->TOP.io_data_out_7}
    , io_data_out_8{vlSymsp->TOP.io_data_out_8}
    , io_data_out_9{vlSymsp->TOP.io_data_out_9}
    , io_const_in_0_matrix_port_0{vlSymsp->TOP.io_const_in_0_matrix_port_0}
    , io_const_in_0_matrix_port_1{vlSymsp->TOP.io_const_in_0_matrix_port_1}
    , io_const_in_0_matrix_port_2{vlSymsp->TOP.io_const_in_0_matrix_port_2}
    , io_const_in_0_matrix_port_3{vlSymsp->TOP.io_const_in_0_matrix_port_3}
    , io_const_in_0_matrix_port_4{vlSymsp->TOP.io_const_in_0_matrix_port_4}
    , io_const_in_0_matrix_port_5{vlSymsp->TOP.io_const_in_0_matrix_port_5}
    , io_const_in_0_matrix_port_6{vlSymsp->TOP.io_const_in_0_matrix_port_6}
    , io_const_in_0_matrix_port_7{vlSymsp->TOP.io_const_in_0_matrix_port_7}
    , io_const_in_0_matrix_port_8{vlSymsp->TOP.io_const_in_0_matrix_port_8}
    , io_const_in_1_matrix_port_0{vlSymsp->TOP.io_const_in_1_matrix_port_0}
    , io_const_in_1_matrix_port_1{vlSymsp->TOP.io_const_in_1_matrix_port_1}
    , io_const_in_1_matrix_port_2{vlSymsp->TOP.io_const_in_1_matrix_port_2}
    , io_const_in_1_matrix_port_3{vlSymsp->TOP.io_const_in_1_matrix_port_3}
    , io_const_in_1_matrix_port_4{vlSymsp->TOP.io_const_in_1_matrix_port_4}
    , io_const_in_1_matrix_port_5{vlSymsp->TOP.io_const_in_1_matrix_port_5}
    , io_const_in_1_matrix_port_6{vlSymsp->TOP.io_const_in_1_matrix_port_6}
    , io_const_in_1_matrix_port_7{vlSymsp->TOP.io_const_in_1_matrix_port_7}
    , io_const_in_1_matrix_port_8{vlSymsp->TOP.io_const_in_1_matrix_port_8}
    , io_const_in_2_matrix_port_0{vlSymsp->TOP.io_const_in_2_matrix_port_0}
    , io_const_in_2_matrix_port_1{vlSymsp->TOP.io_const_in_2_matrix_port_1}
    , io_const_in_2_matrix_port_2{vlSymsp->TOP.io_const_in_2_matrix_port_2}
    , io_const_in_2_matrix_port_3{vlSymsp->TOP.io_const_in_2_matrix_port_3}
    , io_const_in_2_matrix_port_4{vlSymsp->TOP.io_const_in_2_matrix_port_4}
    , io_const_in_2_matrix_port_5{vlSymsp->TOP.io_const_in_2_matrix_port_5}
    , io_const_in_2_matrix_port_6{vlSymsp->TOP.io_const_in_2_matrix_port_6}
    , io_const_in_2_matrix_port_7{vlSymsp->TOP.io_const_in_2_matrix_port_7}
    , io_const_in_2_matrix_port_8{vlSymsp->TOP.io_const_in_2_matrix_port_8}
    , io_const_in_3_matrix_port_0{vlSymsp->TOP.io_const_in_3_matrix_port_0}
    , io_const_in_3_matrix_port_1{vlSymsp->TOP.io_const_in_3_matrix_port_1}
    , io_const_in_3_matrix_port_2{vlSymsp->TOP.io_const_in_3_matrix_port_2}
    , io_const_in_3_matrix_port_3{vlSymsp->TOP.io_const_in_3_matrix_port_3}
    , io_const_in_3_matrix_port_4{vlSymsp->TOP.io_const_in_3_matrix_port_4}
    , io_const_in_3_matrix_port_5{vlSymsp->TOP.io_const_in_3_matrix_port_5}
    , io_const_in_3_matrix_port_6{vlSymsp->TOP.io_const_in_3_matrix_port_6}
    , io_const_in_3_matrix_port_7{vlSymsp->TOP.io_const_in_3_matrix_port_7}
    , io_const_in_3_matrix_port_8{vlSymsp->TOP.io_const_in_3_matrix_port_8}
    , io_const_in_4_matrix_port_0{vlSymsp->TOP.io_const_in_4_matrix_port_0}
    , io_const_in_4_matrix_port_1{vlSymsp->TOP.io_const_in_4_matrix_port_1}
    , io_const_in_4_matrix_port_2{vlSymsp->TOP.io_const_in_4_matrix_port_2}
    , io_const_in_4_matrix_port_3{vlSymsp->TOP.io_const_in_4_matrix_port_3}
    , io_const_in_4_matrix_port_4{vlSymsp->TOP.io_const_in_4_matrix_port_4}
    , io_const_in_4_matrix_port_5{vlSymsp->TOP.io_const_in_4_matrix_port_5}
    , io_const_in_4_matrix_port_6{vlSymsp->TOP.io_const_in_4_matrix_port_6}
    , io_const_in_4_matrix_port_7{vlSymsp->TOP.io_const_in_4_matrix_port_7}
    , io_const_in_4_matrix_port_8{vlSymsp->TOP.io_const_in_4_matrix_port_8}
    , io_const_in_5_matrix_port_0{vlSymsp->TOP.io_const_in_5_matrix_port_0}
    , io_const_in_5_matrix_port_1{vlSymsp->TOP.io_const_in_5_matrix_port_1}
    , io_const_in_5_matrix_port_2{vlSymsp->TOP.io_const_in_5_matrix_port_2}
    , io_const_in_5_matrix_port_3{vlSymsp->TOP.io_const_in_5_matrix_port_3}
    , io_const_in_5_matrix_port_4{vlSymsp->TOP.io_const_in_5_matrix_port_4}
    , io_const_in_5_matrix_port_5{vlSymsp->TOP.io_const_in_5_matrix_port_5}
    , io_const_in_5_matrix_port_6{vlSymsp->TOP.io_const_in_5_matrix_port_6}
    , io_const_in_5_matrix_port_7{vlSymsp->TOP.io_const_in_5_matrix_port_7}
    , io_const_in_5_matrix_port_8{vlSymsp->TOP.io_const_in_5_matrix_port_8}
    , io_const_in_6_matrix_port_0{vlSymsp->TOP.io_const_in_6_matrix_port_0}
    , io_const_in_6_matrix_port_1{vlSymsp->TOP.io_const_in_6_matrix_port_1}
    , io_const_in_6_matrix_port_2{vlSymsp->TOP.io_const_in_6_matrix_port_2}
    , io_const_in_6_matrix_port_3{vlSymsp->TOP.io_const_in_6_matrix_port_3}
    , io_const_in_6_matrix_port_4{vlSymsp->TOP.io_const_in_6_matrix_port_4}
    , io_const_in_6_matrix_port_5{vlSymsp->TOP.io_const_in_6_matrix_port_5}
    , io_const_in_6_matrix_port_6{vlSymsp->TOP.io_const_in_6_matrix_port_6}
    , io_const_in_6_matrix_port_7{vlSymsp->TOP.io_const_in_6_matrix_port_7}
    , io_const_in_6_matrix_port_8{vlSymsp->TOP.io_const_in_6_matrix_port_8}
    , io_const_in_7_matrix_port_0{vlSymsp->TOP.io_const_in_7_matrix_port_0}
    , io_const_in_7_matrix_port_1{vlSymsp->TOP.io_const_in_7_matrix_port_1}
    , io_const_in_7_matrix_port_2{vlSymsp->TOP.io_const_in_7_matrix_port_2}
    , io_const_in_7_matrix_port_3{vlSymsp->TOP.io_const_in_7_matrix_port_3}
    , io_const_in_7_matrix_port_4{vlSymsp->TOP.io_const_in_7_matrix_port_4}
    , io_const_in_7_matrix_port_5{vlSymsp->TOP.io_const_in_7_matrix_port_5}
    , io_const_in_7_matrix_port_6{vlSymsp->TOP.io_const_in_7_matrix_port_6}
    , io_const_in_7_matrix_port_7{vlSymsp->TOP.io_const_in_7_matrix_port_7}
    , io_const_in_7_matrix_port_8{vlSymsp->TOP.io_const_in_7_matrix_port_8}
    , io_const_in_8_matrix_port_0{vlSymsp->TOP.io_const_in_8_matrix_port_0}
    , io_const_in_8_matrix_port_1{vlSymsp->TOP.io_const_in_8_matrix_port_1}
    , io_const_in_8_matrix_port_2{vlSymsp->TOP.io_const_in_8_matrix_port_2}
    , io_const_in_8_matrix_port_3{vlSymsp->TOP.io_const_in_8_matrix_port_3}
    , io_const_in_8_matrix_port_4{vlSymsp->TOP.io_const_in_8_matrix_port_4}
    , io_const_in_8_matrix_port_5{vlSymsp->TOP.io_const_in_8_matrix_port_5}
    , io_const_in_8_matrix_port_6{vlSymsp->TOP.io_const_in_8_matrix_port_6}
    , io_const_in_8_matrix_port_7{vlSymsp->TOP.io_const_in_8_matrix_port_7}
    , io_const_in_8_matrix_port_8{vlSymsp->TOP.io_const_in_8_matrix_port_8}
    , io_const_in_9_matrix_port_0{vlSymsp->TOP.io_const_in_9_matrix_port_0}
    , io_const_in_9_matrix_port_1{vlSymsp->TOP.io_const_in_9_matrix_port_1}
    , io_const_in_9_matrix_port_2{vlSymsp->TOP.io_const_in_9_matrix_port_2}
    , io_const_in_9_matrix_port_3{vlSymsp->TOP.io_const_in_9_matrix_port_3}
    , io_const_in_9_matrix_port_4{vlSymsp->TOP.io_const_in_9_matrix_port_4}
    , io_const_in_9_matrix_port_5{vlSymsp->TOP.io_const_in_9_matrix_port_5}
    , io_const_in_9_matrix_port_6{vlSymsp->TOP.io_const_in_9_matrix_port_6}
    , io_const_in_9_matrix_port_7{vlSymsp->TOP.io_const_in_9_matrix_port_7}
    , io_const_in_9_matrix_port_8{vlSymsp->TOP.io_const_in_9_matrix_port_8}
    , io_io_out_data{vlSymsp->TOP.io_io_out_data}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vconv_cal::Vconv_cal(const char* _vcname__)
    : Vconv_cal(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vconv_cal::~Vconv_cal() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vconv_cal___024root___eval_initial(Vconv_cal___024root* vlSelf);
void Vconv_cal___024root___eval_settle(Vconv_cal___024root* vlSelf);
void Vconv_cal___024root___eval(Vconv_cal___024root* vlSelf);
#ifdef VL_DEBUG
void Vconv_cal___024root___eval_debug_assertions(Vconv_cal___024root* vlSelf);
#endif  // VL_DEBUG
void Vconv_cal___024root___final(Vconv_cal___024root* vlSelf);

static void _eval_initial_loop(Vconv_cal__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vconv_cal___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vconv_cal___024root___eval_settle(&(vlSymsp->TOP));
        Vconv_cal___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vconv_cal::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vconv_cal::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vconv_cal___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vconv_cal___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vconv_cal::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vconv_cal::final() {
    Vconv_cal___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vconv_cal::hierName() const { return vlSymsp->name(); }
const char* Vconv_cal::modelName() const { return "Vconv_cal"; }
unsigned Vconv_cal::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vconv_cal::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vconv_cal___024root__trace_init_top(Vconv_cal___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vconv_cal___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vconv_cal___024root*>(voidSelf);
    Vconv_cal__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vconv_cal___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vconv_cal___024root__trace_register(Vconv_cal___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vconv_cal::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vconv_cal___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
