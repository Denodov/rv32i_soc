// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_xor4.h for the primary calling header

#include "Vtb_xor4__pch.h"

void Vtb_xor4___024root___ctor_var_reset(Vtb_xor4___024root* vlSelf);

Vtb_xor4___024root::Vtb_xor4___024root(Vtb_xor4__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtb_xor4___024root___ctor_var_reset(this);
}

void Vtb_xor4___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_xor4___024root::~Vtb_xor4___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
