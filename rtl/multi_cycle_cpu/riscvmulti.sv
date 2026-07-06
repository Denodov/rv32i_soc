// Processor module

module riscvmulti(input  logic clk, reset,
                  output logic        MemWrite,
                  output logic [31:0] DataAdr, WriteData,
                  input  logic [31:0] ReadData);

    logic [31:0] Instr;
    logic        Zero, PCWrite, IRWrite, RegWrite, AdrSrc;
    logic [1:0]  ResultSrc, ALUSrcB, ALUSrcA, ImmSrc;
    logic [2:0]  ALUControl;

    controller c(
        .clk(clk), .reset(reset),

        // Next address
        .AdrSrc(AdrSrc),

        // Instruction fields
        .op(Instr[6:0]), .funct3(Instr[14:12]), .funct7b5(Instr[30]),

        // ALU Control
        .Zero(Zero), .ALUControl(ALUControl),
        // ALU MUX
        .ALUSrcA(ALUSrcA), .ALUSrcB(ALUSrcB),

        // Write signals
        .PCWrite(PCWrite), .MemWrite(MemWrite),
        .IRWrite(IRWrite), .RegWrite(RegWrite),

        // Extend Unit
        .ImmSrc(ImmSrc),

        // Result selector
        .ResultSrc(ResultSrc)
        );

    datapath dp(
        .clk(clk), .reset(reset),

        // Next address
        .AdrSrc(AdrSrc),

        // ALU Control
        .Zero(Zero), .ALUControl(ALUControl),
        // ALU MUX
        .ALUSrcA(ALUSrcA), .ALUSrcB(ALUSrcB),

        // Write signals
        .PCWrite(PCWrite),
        .IRWrite(IRWrite), .RegWrite(RegWrite),

        // Extend Unit
        .ImmSrc(ImmSrc),

        // Data paths
        .Instr(Instr), .DataAdr(DataAdr), 
        .ReadData(ReadData), .WriteData(WriteData),

        // Result selector
        .ResultSrc(ResultSrc)
        );

endmodule
