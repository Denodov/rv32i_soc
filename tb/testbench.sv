// Testbench for single, multi, pipelined CPUs

module  testbench();

    logic        clk;
    logic        reset;
    logic [31:0] WriteData, DataAdr;
    logic        MemWrite;

// instantiate device to be tested
    top dut(clk, reset, WriteData, DataAdr, MemWrite);

// initialize test

string vcdfile;

    initial
        begin
            reset = 1; #22; reset = 0;

            if (!$value$plusargs("vcd=%s", vcdfile))
                vcdfile = "cpu.vcd";

            $dumpfile(vcdfile);
            $dumpvars(0, testbench);
        end

// generate clock to sequence tests
    always
        begin
            clk <= 1; #5; clk <= 0; #5;
        end

// check results
    always @(negedge clk)
        begin
            if (MemWrite) begin
                if (DataAdr === 100 && WriteData === 25) begin
                    $display("Simulation succeeded");
                    $finish;
                end else if (DataAdr !== 96) begin
                    $fatal(1, "Simulation failed: address=%0d data=%0d",
                              DataAdr, WriteData);
                end
            end
        end
endmodule
