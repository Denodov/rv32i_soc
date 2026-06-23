# Architecture

## Single-Cycle RV32I Processor

The processor implements a single-cycle RV32I RISC-V architecture in SystemVerilog. Each instruction completes execution within a single clock cycle.

### Top-Level Structure

The design is divided into three major subsystems:

1. Control Unit
2. Datapath
3. Memory System

---

## Control Unit

The Control Unit generates all processor control signals required for instruction execution.

### Components

#### Main Decoder (`maindec.sv`)

Decodes the instruction opcode and generates:

* Register write enable
* Memory write enable
* Branch control
* Jump control
* ALU source selection
* Immediate source selection
* Result source selection
* ALU operation code

#### ALU Decoder (`aludec.sv`)

Uses:

* Opcode
* funct3
* funct7

to determine the specific ALU operation.

Supported operations include:

* ADD
* SUB
* AND
* OR
* SLT

#### Controller (`controller.sv`)

Integrates the Main Decoder and ALU Decoder and generates:

* ALUControl
* RegWrite
* MemWrite
* ALUSrc
* ResultSrc
* ImmSrc
* PCSrc

The controller also determines branch and jump behavior using the ALU Zero flag.

---

## Datapath

The Datapath performs instruction execution and data movement throughout the processor.

### Components

#### Program Counter Logic

Files:

* `flopr.sv`
* `adder.sv`
* `mux2.sv`

Responsibilities:

* Store current PC value
* Compute PC + 4
* Compute branch/jump targets
* Select next PC value

---

#### Register File (`regfile.sv`)

Implements the RV32I register set:

* 32 general-purpose registers
* Two read ports
* One write port
* Register x0 hardwired to zero

---

#### Immediate Extension Unit (`extend.sv`)

Generates sign-extended immediates for:

* I-type instructions
* S-type instructions
* B-type instructions
* J-type instructions

---

#### Arithmetic Logic Unit (`alu.sv`)

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

---

#### Multiplexers

Files:

* `mux2.sv`
* `mux3.sv`

Used to select:

* ALU operands
* Next PC source
* Writeback source

---

#### Datapath Integration (`datapath.sv`)

Connects:

* Program Counter
* Register File
* Immediate Generator
* ALU
* Memory Interface
* Writeback Logic

to execute instructions.

---

## Memory System

### Instruction Memory (`imem.sv`)

Stores program instructions.

Features:

* 64-word memory
* Word-aligned instruction fetch
* Program loaded using `$readmemh`

---

### Data Memory (`dmem.sv`)

Stores program data.

Supports:

* Memory reads
* Memory writes
* Word-aligned accesses

---

## Processor Core

### Single-Cycle Core (`riscvsingle.sv`)

Integrates:

* Controller
* Datapath

and forms the complete RV32I processor.

---

## Top-Level System

### Top Module (`top.sv`)

Integrates:

* Single-cycle processor
* Instruction memory
* Data memory

and serves as the top-level simulation and FPGA integration module.
