// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_xor4.h for the primary calling header

#ifndef VERILATED_VTB_XOR4___024ROOT_H_
#define VERILATED_VTB_XOR4___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_xor4__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_xor4___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*3:0*/ tb_xor4__DOT__a;
    CData/*0:0*/ tb_xor4__DOT__yexpected;
    CData/*0:0*/ tb_xor4__DOT__clk;
    CData/*0:0*/ tb_xor4__DOT__reset;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_xor4__DOT__clk__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VinactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*31:0*/ tb_xor4__DOT__vectornum;
    IData/*31:0*/ tb_xor4__DOT__errors;
    IData/*31:0*/ __VactIterCount;
    IData/*31:0*/ __VinactIterCount;
    IData/*31:0*/ __Vi;
    VlUnpacked<CData/*4:0*/, 10001> tb_xor4__DOT__testvectors;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hf90cf04b__0;

    // INTERNAL VARIABLES
    Vtb_xor4__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_xor4___024root(Vtb_xor4__Syms* symsp, const char* namep);
    ~Vtb_xor4___024root();
    VL_UNCOPYABLE(Vtb_xor4___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
