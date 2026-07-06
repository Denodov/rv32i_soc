module controller(input  logic       clk, reset, Zero,
                  input  logic [6:0] op,
                  input  logic [2:0] funct3,
                  input  logic       funct7b5,

                  output logic       PCWrite, RegWrite, MemWrite, IRWrite,
                  output logic       AdrSrc,
                  output logic [1:0] ResultSrc, ALUSrcB, ALUSrcA, ImmSrc,
                  output logic [2:0] ALUControl);

    typedef enum logic [3:0] {
        FETCH, DECODE,
        MEMADR, MEMREAD, MEMWB, MEMWRITE,
        EXECUTER, ALUWB, EXECUTEI,
        JAL, BEQ
    } statetype;

    statetype state, nextstate;

    logic [1:0] ALUOp;
    logic       PCUpdate, Branch;

    // State register
    always_ff @(posedge clk or posedge reset) begin
        if (reset) state <= FETCH;
            else
                state <= nextstate;
    end

    // Next state logic
    always_comb begin
        case (state)
            FETCH: nextstate = DECODE;
            DECODE: begin
                case (op)
                    7'b0000011: nextstate = MEMADR;    // lw
                    7'b0100011: nextstate = MEMADR;    // sw
                    7'b0110011: nextstate = EXECUTER;  // R-type
                    7'b0010011: nextstate = EXECUTEI;  // I-type ALU
                    7'b1101111: nextstate = JAL;       // jal
                    7'b1100011: nextstate = BEQ;       // beq
                    default:    nextstate = FETCH;
                endcase
            end

            MEMADR: begin
                if (op == 7'b0000011)
                    nextstate = MEMREAD;
                else
                    nextstate = MEMWRITE;
            end

            MEMREAD:  nextstate = MEMWB;
            MEMWB:    nextstate = FETCH;
            MEMWRITE: nextstate = FETCH;
            EXECUTER: nextstate = ALUWB;
            ALUWB:    nextstate = FETCH;
            EXECUTEI: nextstate = ALUWB;
            JAL:      nextstate = ALUWB;
            BEQ:      nextstate = FETCH;

            default:  nextstate = FETCH;

        endcase
    end

    assign PCWrite = PCUpdate | (Branch & Zero); // PC logic for fetch, jal, and beq states

    // Output logic
    always_comb begin
        // defaults
        PCUpdate   = 1'b0;
        Branch     = 1'b0;
        RegWrite   = 1'b0;
        MemWrite   = 1'b0;
        IRWrite    = 1'b0;
        AdrSrc     = 1'b0;
        ResultSrc  = 2'b00;
        ALUSrcB    = 2'b00;
        ALUSrcA    = 2'b00;
        ALUOp      = 2'b00;

        case (state)
            FETCH: begin
                AdrSrc    = 1'b0;
                IRWrite   = 1'b1;
                ALUSrcA   = 2'b00; // 1. Gets PC
                ALUSrcB   = 2'b10; // 2. 4
                ALUOp     = 2'b00; // 3. Add PC + 4 
                ResultSrc = 2'b10; // 4. Chooses ALUResult (Sum of PC+4)
                PCUpdate  = 1'b1;
            end

            DECODE: begin
                ALUSrcA   = 2'b01; // Grabs OldPC
                ALUSrcB   = 2'b01; // Grabs ImmExt
                ALUOp     = 2'b00; // Performs addition
            end

            MEMADR: begin          // sw & lw
                ALUSrcA   = 2'b10; // Grabs A
                ALUSrcB   = 2'b01; // Grabs ImmExt
                ALUOp     = 2'b00; // Performs addition 
            end

            MEMREAD: begin         // lw
                ResultSrc = 2'b00; // Grabs ALUOut
                AdrSrc    = 1'b1;  // Chooses ALUOut as address
            end

            MEMWB: begin           // lw
                ResultSrc = 2'b01; // Grabs data
                RegWrite  = 1'b1;  // Writes data to register
            end

            MEMWRITE: begin        // sw
                ResultSrc = 2'b00; // Grabs ALUOut 
                AdrSrc    = 1'b1;  // Chooses ALUOut
                MemWrite  = 1'b1;  // Writes ALUOut to memory (sw)
            end

            EXECUTER: begin        // R-type
                ALUSrcA   = 2'b10; // Grabs A (RD1)
                ALUSrcB   = 2'b00; // Grabs WriteData (RD2)
                ALUOp     = 2'b10; // Use funct3/funct7 to choose ALU operation
            end

            EXECUTEI: begin        // I-type ALU
                ALUSrcA   = 2'b10; // Grabs RD1
                ALUSrcB   = 2'b01; // Grabs ImmExt
                ALUOp     = 2'b10; // Use funct3 to choose I-type ALU operation
            end

            JAL: begin             // Jump and link
                ALUSrcA   = 2'b01; // OldPC
                ALUSrcB   = 2'b10; // 4
                ALUOp     = 2'b00; // Add
                ResultSrc = 2'b00; // Chooses ALUOut
                PCUpdate  = 1'b1;
            end

            ALUWB: begin           // R-type, I-type, jal
                ResultSrc = 2'b00; // Grabs ALUOut
                RegWrite  = 1'b1;  // Writes ALUOut to register
            end

            BEQ: begin             // Branch if equal
                ALUSrcA   = 2'b10; // RD1
                ALUSrcB   = 2'b00; // RD2
                ALUOp     = 2'b01; // Performs subtraction, if Zero, branch taken
                ResultSrc = 2'b00; // Grabs ALUOut (branch target)
                Branch    = 1'b1;  // Zero flag asserts write to PC
            end

            default: begin
            end

        endcase
    end

    // Immediate Source Decoder
    always_comb begin
        case (op)
            7'b0100011: ImmSrc = 2'b01; // S-type
            7'b1100011: ImmSrc = 2'b10; // B-type
            7'b1101111: ImmSrc = 2'b11; // J-type
            default:    ImmSrc = 2'b00; // I-type
        endcase
    end

    // ALU Decoder
    always_comb begin
        case (ALUOp)
            2'b00: ALUControl = 3'b000; // Add
            2'b01: ALUControl = 3'b001; // Subtract
            2'b10: begin
                case (funct3)
                    3'b000: begin
                        if (op[5] && funct7b5)
                            ALUControl = 3'b001; // Subtract
                        else
                            ALUControl = 3'b000; // Add/Addi
                    end

                    3'b010: ALUControl  = 3'b101; // Set less than
                    3'b110: ALUControl  = 3'b011; // Or
                    3'b111: ALUControl  = 3'b010; // And
                    default: ALUControl = 3'bxxx;
                endcase
            end

            default: ALUControl = 3'bxxx;
        endcase
    end
endmodule
