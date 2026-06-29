# Architecture

## Project Overview

This project follows a progressive approach to building a FPGA-based SoC, beginning with a single-cycle RV32I processor and upgrading into more sophisticated impementations. Each stage builds upon the last while offering beneficial design changes and improvements.

### Development Roadmap

* [x] Single-Cycle RV32I Processor
* [ ] Multicycle RV32I Processor
* [ ] 5-Stage Pipelined RV32I Processor
* [ ] FPGA-Based System-on-Chip (SoC)
* [ ] Hardware Accelerator

---

# Single-Cycle RV32I Processor

## Overview

The single-cycle processor implements the RV32I RISC-V instruction set architecture in SystemVerilog. Every instruction completes within a single clock cycle, making this implementation straightforward to understand and verify while serving as the architectural foundation for future processor designs.

## Top-Level Structure

The processor consists of three primary subsystems:

1. Control Unit
2. Datapath
3. Memory System

---

## Control Unit

The Control Unit generates all control signals required to execute RV32I instructions.

### Main Decoder (`maindec.sv`)

Decodes the instruction opcode and generates:

* Register write enable
* Memory write enable
* Branch control
* Jump control
* ALU source selection
* Immediate source selection
* Result source selection
* ALU operation code

### ALU Decoder (`aludec.sv`)

Uses:

* Opcode
* funct3
* funct7

to determine the required ALU operation.

Supported operations include:

* ADD
* SUB
* AND
* OR
* SLT

### Controller (`controller.sv`)

Combines the Main Decoder and ALU Decoder to generate:

* ALUControl
* RegWrite
* MemWrite
* ALUSrc
* ResultSrc
* ImmSrc
* PCSrc

Branch and jump decisions are generated using the ALU Zero flag.

---

## Datapath

The datapath performs instruction execution and transfers data between processor components.

### Program Counter Logic

Files:

* `flopr.sv`
* `adder.sv`
* `mux2.sv`

Responsibilities:

* Maintain the Program Counter
* Compute PC + 4
* Compute branch and jump targets
* Select the next Program Counter value

### Register File (`regfile.sv`)

Implements:

* 32 general-purpose registers
* Two combinational read ports
* One synchronous write port
* Hardwired x0 register

### Immediate Extension Unit (`extend.sv`)

Generates sign-extended immediates for:

* I-type
* S-type
* B-type
* J-type

instructions.

### Arithmetic Logic Unit (`alu.sv`)

Performs arithmetic and logical operations.

Supported operations:

* ADD
* SUB
* AND
* OR
* SLT

Outputs:

* ALU Result
* Zero Flag

### Multiplexers

Files:

* `mux2.sv`
* `mux3.sv`

Used for:

* ALU operand selection
* Program Counter selection
* Writeback source selection

### Datapath Integration (`datapath.sv`)

Connects:

* Program Counter
* Register File
* Immediate Generator
* ALU
* Memory Interface
* Writeback Logic

to execute RV32I instructions.

---

## Memory System

### Instruction Memory (`imem.sv`)

Features:

* 64-word instruction memory
* Word-aligned instruction fetch
* Program initialization using `$readmemh`

### Data Memory (`dmem.sv`)

Supports:

* Memory reads
* Memory writes
* Word-aligned accesses

---

## Processor Core

### Single-Cycle Core (`riscvsingle.sv`)

Integrates the Controller and Datapath into a complete RV32I processor.

### Top-Level Module (`top.sv`)

Integrates:

* Single-cycle processor
* Instruction memory
* Data memory

and serves as the top-level simulation module.

---

# Multicycle RV32I Processor

## Overview

The multicycle processor extends the single-cycle architecture by dividing instruction execution across multiple clock cycles. Instead of completing every instruction in one clock cycle, the processor sequences instructions through multiple states controlled by a finite-state machine.

This design reuses hardware resources across cycles, including the ALU, register file, memory interface, and intermediate datapath registers.

## Current Status

- [x] Multicycle datapath diagram
- [x] Controller diagram
- [x] FSM control design
- [x] Instruction execution sequencing
- [x] Control signal planning
- [ ] SystemVerilog implementation
- [ ] Simulation testbench
- [ ] Verification

## Design Components

### Datapath

The multicycle datapath has been designed to support staged instruction execution across multiple cycles.

Planned datapath elements include:

- Program Counter
- Instruction Register
- Register File
- ALU
- ALUOut Register
- Memory Data Register
- Immediate Extension Unit
- Multiplexers for ALU source, PC source, and result selection

### Controller

The controller is designed as a finite-state machine responsible for sequencing each instruction through the required execution states.

The FSM controls:

- Instruction fetch
- Instruction decode
- ALU execution
- Memory access
- Register writeback
- Branch and jump behavior

### FSM

The multicycle FSM has been designed to generate cycle-specific control signals for each instruction class.

Planned instruction classes include:

- R-type arithmetic/logical instructions
- I-type immediate instructions
- Load instructions
- Store instructions
- Branch instructions
- Jump instructions

## Next Step

The next step is translating the completed architecture, datapath diagram, controller diagram, and FSM design into SystemVerilog modules and verifying the implementation through simulation.

---

# 5-Stage Pipelined RV32I Processor

## Overview

*Under development.*

The pipelined processor will execute multiple instructions concurrently by dividing execution into five pipeline stages:

* Instruction Fetch (IF)
* Instruction Decode (ID)
* Execute (EX)
* Memory Access (MEM)
* Writeback (WB)

The implementation will include hazard detection, forwarding, and pipeline control logic.

---

# FPGA-Based SoC

## Overview

*Planned.*

The final processor will be integrated into an FPGA-based System-on-Chip containing memory-mapped peripherals, a system bus, and external interfaces.

---

# Hardware Accelerator

## Overview

*Planned.*
