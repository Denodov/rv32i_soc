// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_xor4.h for the primary calling header

#include "Vtb_xor4__pch.h"

VlCoroutine Vtb_xor4___024root___eval_initial__TOP__Vtiming__0(Vtb_xor4___024root* vlSelf);
VlCoroutine Vtb_xor4___024root___eval_initial__TOP__Vtiming__1(Vtb_xor4___024root* vlSelf);
VlCoroutine Vtb_xor4___024root___eval_initial__TOP__Vtiming__2(Vtb_xor4___024root* vlSelf);

void Vtb_xor4___024root___eval_initial(Vtb_xor4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___eval_initial\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_xor4___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_xor4___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_xor4___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

VlCoroutine Vtb_xor4___024root___eval_initial__TOP__Vtiming__0(Vtb_xor4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile("xor4.vcd"s);
    vlSymsp->_traceDumpOpen();
    VL_READMEM_N(false, 5, 10001, 0, "xor4tb.txt"s,  &(vlSelfRef.tb_xor4__DOT__testvectors)
                 , 0, ~0ULL);
    vlSelfRef.tb_xor4__DOT__vectornum = 0U;
    vlSelfRef.tb_xor4__DOT__errors = 0U;
    vlSelfRef.tb_xor4__DOT__reset = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000000016ULL, 
                                         nullptr, "tb_xor4.sv", 
                                         26);
    vlSelfRef.tb_xor4__DOT__reset = 0U;
    co_return;
}

VlCoroutine Vtb_xor4___024root___eval_initial__TOP__Vtiming__1(Vtb_xor4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        vlSelfRef.tb_xor4__DOT__clk = 1U;
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "tb_xor4.sv", 
                                             14);
        vlSelfRef.tb_xor4__DOT__clk = 0U;
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "tb_xor4.sv", 
                                             14);
    }
    co_return;
}

void Vtb_xor4___024root____VbeforeTrig_hf90cf04b__0(Vtb_xor4___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vtb_xor4___024root___eval_initial__TOP__Vtiming__2(Vtb_xor4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_xor4___024root____VbeforeTrig_hf90cf04b__0(vlSelf, 
                                                       "@(posedge tb_xor4.clk)");
        co_await vlSelfRef.__VtrigSched_hf90cf04b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_xor4.clk)", 
                                                             "tb_xor4.sv", 
                                                             30);
        co_await vlSelfRef.__VdlySched.delay(1ULL, 
                                             nullptr, 
                                             "tb_xor4.sv", 
                                             32);
        vlSelfRef.tb_xor4__DOT__a = (0x0000000fU & 
                                     (((0x2710U >= 
                                        (0x00003fffU 
                                         & vlSelfRef.tb_xor4__DOT__vectornum))
                                        ? vlSelfRef.tb_xor4__DOT__testvectors
                                       [(0x00003fffU 
                                         & vlSelfRef.tb_xor4__DOT__vectornum)]
                                        : 0U) >> 1U));
        vlSelfRef.tb_xor4__DOT__yexpected = ((0x2710U 
                                              >= (0x00003fffU 
                                                  & vlSelfRef.tb_xor4__DOT__vectornum))
                                              ? (1U 
                                                 & vlSelfRef.tb_xor4__DOT__testvectors
                                                 [(0x00003fffU 
                                                   & vlSelfRef.tb_xor4__DOT__vectornum)])
                                              : 0U);
    }
    co_return;
}

void Vtb_xor4___024root___eval_triggers_vec__act(Vtb_xor4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___eval_triggers_vec__act\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((IData)(vlSelfRef.tb_xor4__DOT__clk) 
                                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_xor4__DOT__clk__0))) 
                                                      << 2U) 
                                                     | ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                         << 1U) 
                                                        | ((~ (IData)(vlSelfRef.tb_xor4__DOT__clk)) 
                                                           & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_xor4__DOT__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_xor4__DOT__clk__0 
        = vlSelfRef.tb_xor4__DOT__clk;
}

bool Vtb_xor4___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtb_xor4___024root___nba_sequent__TOP__0(Vtb_xor4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___nba_sequent__TOP__0\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ (IData)(vlSelfRef.tb_xor4__DOT__reset)))) {
        if (VL_UNLIKELY((((1U & VL_REDXOR_4(vlSelfRef.tb_xor4__DOT__a)) 
                          != (IData)(vlSelfRef.tb_xor4__DOT__yexpected))))) {
            VL_WRITEF_NX("Error inputs = %b\n",1, '#',4,vlSelfRef.tb_xor4__DOT__a);
            vlSelfRef.tb_xor4__DOT__errors = ((IData)(1U) 
                                              + vlSelfRef.tb_xor4__DOT__errors);
            VL_WRITEF_NX(" outputs = %b (%b expected)\n",2
                         , '#',1,(1U & VL_REDXOR_4(vlSelfRef.tb_xor4__DOT__a))
                         , '#',1,(IData)(vlSelfRef.tb_xor4__DOT__yexpected));
        }
        vlSelfRef.tb_xor4__DOT__vectornum = ((IData)(1U) 
                                             + vlSelfRef.tb_xor4__DOT__vectornum);
        if (VL_UNLIKELY(((0x00000010U == vlSelfRef.tb_xor4__DOT__vectornum)))) {
            VL_WRITEF_NX("%d tests completed with %d errors\n",2
                         , '#',32,vlSelfRef.tb_xor4__DOT__vectornum
                         , '#',32,vlSelfRef.tb_xor4__DOT__errors);
            VL_FINISH_MT("tb_xor4.sv", 48, "");
        }
    }
}

void Vtb_xor4___024root___eval_nba(Vtb_xor4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___eval_nba\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_xor4___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vtb_xor4___024root___timing_ready(Vtb_xor4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___timing_ready\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_hf90cf04b__0.ready("@(posedge tb_xor4.clk)");
    }
}

void Vtb_xor4___024root___timing_resume(Vtb_xor4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___timing_resume\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_hf90cf04b__0.moveToResumeQueue(
                                                          "@(posedge tb_xor4.clk)");
    vlSelfRef.__VtrigSched_hf90cf04b__0.resume("@(posedge tb_xor4.clk)");
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_xor4___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_xor4___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_xor4___024root___eval_phase__act(Vtb_xor4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___eval_phase__act\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_xor4___024root___eval_triggers_vec__act(vlSelf);
    Vtb_xor4___024root___timing_ready(vlSelf);
    Vtb_xor4___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_xor4___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_xor4___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_xor4___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_xor4___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_xor4___024root___eval_phase__inact(Vtb_xor4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___eval_phase__inact\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("tb_xor4.sv", 1, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_xor4___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_xor4___024root___eval_phase__nba(Vtb_xor4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___eval_phase__nba\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_xor4___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_xor4___024root___eval_nba(vlSelf);
        Vtb_xor4___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_xor4___024root___eval(Vtb_xor4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___eval\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_xor4___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("tb_xor4.sv", 1, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("tb_xor4.sv", 1, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtb_xor4___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("tb_xor4.sv", 1, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtb_xor4___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtb_xor4___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtb_xor4___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

void Vtb_xor4___024root____VbeforeTrig_hf90cf04b__0(Vtb_xor4___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root____VbeforeTrig_hf90cf04b__0\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)((((IData)(vlSelfRef.tb_xor4__DOT__clk) 
                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_xor4__DOT__clk__0))) 
                                  << 2U)));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_xor4__DOT__clk__0 
        = vlSelfRef.tb_xor4__DOT__clk;
    if ((4ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_hf90cf04b__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vtb_xor4___024root___eval_debug_assertions(Vtb_xor4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_xor4___024root___eval_debug_assertions\n"); );
    Vtb_xor4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
