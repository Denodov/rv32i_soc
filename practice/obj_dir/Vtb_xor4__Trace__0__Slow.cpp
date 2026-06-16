// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_xor4__Syms.h"


VL_ATTR_COLD void Vtb_xor4___024root__trace_init_sub__TOP__0(Vtb_xor4___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root__trace_init_sub__TOP__0\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "tb_xor4", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"yexpected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+3,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+4,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+5,0,"vectornum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+6,0,"errors",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "dut", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"y",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_xor4___024root__trace_init_top(Vtb_xor4___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root__trace_init_top\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_xor4___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_xor4___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_xor4___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_xor4___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_xor4___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_xor4___024root__trace_register(Vtb_xor4___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root__trace_register\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtb_xor4___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtb_xor4___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtb_xor4___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtb_xor4___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_xor4___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root__trace_const_0\n"); );
    // Body
    Vtb_xor4___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_xor4___024root*>(voidSelf);
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vtb_xor4___024root__trace_full_0_sub_0(Vtb_xor4___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_xor4___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root__trace_full_0\n"); );
    // Body
    Vtb_xor4___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_xor4___024root*>(voidSelf);
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb_xor4___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_xor4___024root__trace_full_0_sub_0(Vtb_xor4___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root__trace_full_0_sub_0\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullCData(oldp+0,(vlSelfRef.tb_xor4__DOT__a),4);
    bufp->fullBit(oldp+1,((1U & VL_REDXOR_4(vlSelfRef.tb_xor4__DOT__a))));
    bufp->fullBit(oldp+2,(vlSelfRef.tb_xor4__DOT__yexpected));
    bufp->fullBit(oldp+3,(vlSelfRef.tb_xor4__DOT__clk));
    bufp->fullBit(oldp+4,(vlSelfRef.tb_xor4__DOT__reset));
    bufp->fullIData(oldp+5,(vlSelfRef.tb_xor4__DOT__vectornum),32);
    bufp->fullIData(oldp+6,(vlSelfRef.tb_xor4__DOT__errors),32);
}
