module shift_register16x8 (
  input clk,
  input shift_in,
  output reg [15:0] A,
  output reg [15:0] B,
  output reg [15:0] C,
  output reg [15:0] D,
  output reg [15:0] E,
  output reg [15:0] F,
  output reg [15:0] G,
  output reg [15:0] H
);

  // Shift the data through the stages on every positive clock edge
  always @(posedge clk) begin
    A <= shift_in;
    B <= A;
    C <= B;
    D <= C;
    E <= D;
    F <= E;
    G <= F;
    H <= G;
  end
endmodule
module tb_shift_register;

  // Declare signals
  reg clk, shift_in;
  wire [15:0] A, B, C, D, E, F, G, H;

  // Instantiate the shift register module
  shift_register16x8 dut (clk, shift_in, A, B, C, D, E, F, G, H);

  // Initial block for test pattern and verification
  initial begin
    clk = 1'b0;
    shift_in = 1'b0;

    // Wait for initial delays
    #5;

    // Apply a test pattern (shift in a 1 followed by 7 zeros)
    shift_in = 1'b1;
    #10; // Shift in a 1

    // Ensure enough clock cycles for complete shift
    #90; // 80 for shifting + 10 margin

    // Verify the shifted data
    if (A == 16'b0000_0000_0000_0001 &&
        B == 16'b0000_0000_0000_0010 &&
        C == 16'b0000_0000_0000_0100 &&
        D == 16'b0000_0000_0000_1000 &&
        E == 16'b0000_0000_0001_0000 &&
        F == 16'b0000_0000_0010_0000 &&
        G == 16'b0000_0000_0100_0000 &&
        H == 16'b0000_0000_1000_0000) begin
      $display("Shift register test passed!");
    end else begin
      $display("Shift register test failed!");
    end

    #10;
    $finish;
  end

  // Generate clock signal
  always begin
    #5;
    clk = ~clk;
  end

endmodule
