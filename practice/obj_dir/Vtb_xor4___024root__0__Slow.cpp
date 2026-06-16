// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_xor4.h for the primary calling header

#include "Vtb_xor4__pch.h"

void Vtb_xor4___024root___timing_ready(Vtb_xor4___024root* vlSelf);

VL_ATTR_COLD void Vtb_xor4___024root___eval_static(Vtb_xor4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___eval_static\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_xor4__DOT__clk__0 
        = vlSelfRef.tb_xor4__DOT__clk;
    Vtb_xor4___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vtb_xor4___024root___eval_final(Vtb_xor4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___eval_final\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_xor4___024root___eval_settle(Vtb_xor4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___eval_settle\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vtb_xor4___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_xor4___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_xor4___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(negedge tb_xor4.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge tb_xor4.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_xor4___024root___ctor_var_reset(Vtb_xor4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___ctor_var_reset\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_xor4__DOT__a = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12604171899184840303ull);
    vlSelf->tb_xor4__DOT__yexpected = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8169456317934510452ull);
    vlSelf->tb_xor4__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13452225253129294956ull);
    vlSelf->tb_xor4__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7844928306802600668ull);
    vlSelf->tb_xor4__DOT__vectornum = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16207801646884899540ull);
    vlSelf->tb_xor4__DOT__errors = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2461935735013405345ull);
    for (int __Vi0 = 0; __Vi0 < 10001; ++__Vi0) {
        vlSelf->tb_xor4__DOT__testvectors[__Vi0] = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17647833057428585826ull);
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_xor4__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
