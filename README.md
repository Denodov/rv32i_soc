# RV32I Processors and FPGA SoC

A collection of RISC-V processor implementations developed in SystemVerilog as part of a long-term computer architecture and digital design project.

The goal of this project is to progressively develop increasingly sophisticated RV32I processor implementations, beginning with a verified single-cycle processor and eventually expanding to multicycle, pipelined, FPGA-based SoC, and hardware accelerator designs.

## Goals
- Single-cycle RV32I CPU
- Multi-cycle RV32I CPU
- 5-stage pipeline
- FPGA implementation
- SoC integration
- Hardware accelerator

## Current Status
- [x] Single-cycle CPU
- [ ] Multi-cycle CPU
- [ ] Pipelined CPU

## Tools
- SystemVerilog
- Verilator
- GTKWave
- Git
- GitHub
- Linux

## Verification
The single-cycle processor has been verified using the reference validation program supplied with the Harris & Harris implementation.

Simulation workflow:

SystemVerilog
→ Verilator
→ GTKWave
→ Debug
→ Verify

### References
- Harris, S., & Harris, D. (2021). Digital Design and Computer Architecture: RISC-V Edition. Morgan Kaufmann.
- Patterson, D. A., & Hennessy, J. L. (2020). Computer Organization and Design: RISC-V Edition, The Hardware/Software Interface (2nd ed.). Morgan Kaufmann.

### Acknowledgements
The RV32I processor implementation was developed using the architecture, design methodology, and reference materials presented in Digital Design and Computer Architecture: RISC-V Edition by Sarah Harris and David Harris.

Additional architectural concepts and computer organization principles were studied from Computer Organization and Design: RISC-V Edition by David Patterson and John Hennessy.

The SystemVerilog implementation, simulation environment, integraton, debugging, verification workflow, and future project extensions are developed independently.
