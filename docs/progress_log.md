# 06-05-2026 to 06-13-2026

* Studied single-cycle CPU architecture
* Drew diagrams and truth tables
* Used RISC-V instructions for datapaths and control signals

# 06-14-2026

Implemented:

* Adder
* 2:1 and 3:1 Multiplexers
* Resettable Flip-Flop and Resettable Flip-Flop with enable
* ALU

---

# 06-16-2026

Implemented:
* Project repository structure
* GitHub integration
* Verilator simulation workflow
* GTKWave waveform analysis workflow
* Associated testbenches of adder, muxes, and ALU

Verified:
* Successful compilation and execution of SystemVerilog modules
* Waveform generation and inspection in GTKWave
* Adder add/sub operations
* Multiplexer select logic
* Flip-Flops
* ALU combinatonal and logical operations.

---

# 06-17-2026 to 06-19-2026

Implemented:

* Single-cycle processor module
* Controller
* Main Decoder
* ALU Decoder
* Datapath

---

# 6-20-2026 to 6-23-2026

Implemented:

* Extend Unit
* Top-level module
* Instruction Memory
* Data Memory
* Testbench

Fixed:

* Register file address width mismatch
* Instruction memory indexing warnings
* Data memory indexing warnings
* Signal capitalization inconsistencies
* Missing control signal declarations
* Instruction memory loading path issues
* Testbench reset behavior
* Module integration and wiring issues

Verified:

* Single-cycle RV32I processor using Harris & Harris reference validation program
* Instruction fetch functionality
* Datapath operation
* Control path operation
* Memory read/write functionality
* Processor execution flow
* Successful compilation of complete processor design
* Successful simulation of integrated CPU
* Correct waveform generation for CPU-level signals

Result:

* Processor passed reference testbench verification
* Simulation completed successfully


# 06-24-2026

* Studied multicycle CPU architecture
* Began forming initial processor diagram

# 6-26-2026

* Finished base diagram for multicycle CPU
* Used RISC-V instructions for datapaths and control signals

# 6-27-2026

* Drew controller diagram and FSM for control signals

# 6-28-2026

* Added finished diagrams to docs
* Re-organized diagrams folder to allow for multiple CPUs
* Reviewed single-cycle HDL and added comments
* Added new folder in rtl/ for multicycle CPU HDL
* Wrote top-level module 






