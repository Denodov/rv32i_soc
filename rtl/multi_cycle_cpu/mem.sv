// Instruction/Data Memory

module mem(input  logic        clk, we,
           input  logic [31:0] a, wd,
           output logic [31:0] rd);

    logic [31:0] RAM[63:0];

    initial
        $readmemh("software/hex/riscvtest.txt", RAM);

    assign rd = RAM[a[7:2]];

    always_ff @(clk)
        if (we) RAM[a[7:2]] <= wd;
endmodule
