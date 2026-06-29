// Data Memory

module dmem(input  logic        clk, we,
            input  logic [31:0] a, wd,
            output logic [31:0] rd);

    logic [31:0] RAM[63:0];

    assign rd = RAM[a[7:2]]; // last 2 bits ignored,
                             // memory has only 64 entries,
                             // so only 6 bits needed to index

    always_ff @(posedge clk)
        if (we) RAM[a[7:2]] <= wd;
endmodule
