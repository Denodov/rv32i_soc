// ALU

module alu(
    input  logic [31:0] a,
    input  logic [31:0] b,
    input  logic [2:0]  alucontrol,
    output logic [31:0] result,
    output logic        zero
);

    always_comb begin
        case (alucontrol)
            3'b000: result = a + b;                    // add
            3'b001: result = a - b;                    // subtract
            3'b010: result = a & b;                    // and
            3'b011: result = a | b;                    // or
            3'b101: result = ($signed(a) < $signed(b)) ? 32'd1 : 32'd0; // slt
            default: result = 32'bx;
        endcase
    end

    assign zero = (result == 32'b0);

endmodule
