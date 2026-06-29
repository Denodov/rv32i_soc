// Instruction memory

module imem(input  logic [31:0] a,
            output logic [31:0] rd);

    logic [31:0] RAM[63:0];

    initial
        $readmemh("software/hex/riscvtest.txt", RAM);

    assign rd = RAM[a[7:2]]; // last 2 bits ignored,
                             // memory has only 64 entries,
                             // so only 6 bits needed to index
endmodule
