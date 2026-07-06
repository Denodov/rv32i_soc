module datapath(input  logic        clk, reset,
                input  logic        PCWrite, AdrSrc, IRWrite, RegWrite,
                input  logic [1:0]  ResultSrc, ALUSrcA, ALUSrcB, ImmSrc,
                input  logic [2:0]  ALUControl,
                input  logic [31:0] ReadData,
                output logic        Zero,
                output logic [31:0] Instr, WriteData, DataAdr);

                // Combinational/internal signals
                logic [31:0] PC, ALUResult, Result,
                             SrcA, SrcB, ImmExt, RD1, RD2;
                // Register outputs
                logic [31:0] OldPC, Data, A, ALUOut;

                // instuction/data memory address selection
                mux2 #(32) adrmux(PC, Result, AdrSrc, DataAdr);

                // state registers
                flopren #(32) pcreg(clk, reset, PCWrite, Result, PC);
                flopren #(32) oldpcreg(clk, reset, IRWrite, PC, OldPC);
                flopren #(32) instrreg(clk, reset, IRWrite, ReadData, Instr);
                flopr   #(32) datareg(clk, reset, ReadData, Data);

                // register file logic
                regfile rf(clk, RegWrite,
                           Instr[19:15], Instr[24:20], Instr[11:7],
                           Result, RD1, RD2);
                // register file state registers
                flopr #(32) areg(clk, reset, RD1, A);
                flopr #(32) breg(clk, reset, RD2, WriteData);

                // immediate extension
                extend ext(Instr[31:7], ImmSrc, ImmExt);

                // ALU input selection
                mux3 #(32) srcamux(PC, OldPC, A, ALUSrcA, SrcA);
                mux3 #(32) srcbmux(WriteData, ImmExt, 32'd4, ALUSrcB, SrcB);
                // ALU logic 
                alu alu(SrcA, SrcB, ALUControl, ALUResult, Zero);
                // ALU state register
                flopr #(32) alureg(clk, reset, ALUResult, ALUOut);
                // ALU result selection
                mux3 #(32) resultmux(ALUOut, Data, ALUResult, 
                                     ResultSrc, Result);
endmodule
