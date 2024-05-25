// 7.1.1 How does a Verilog model for a D-flip-flop han-dle treating reset as the highest priority input?


module dff (
  input clk,
  input reset,
  input D,
  output reg q
);

  always @(posedge clk or negedge reset) begin
    if (!reset) begin 
      q <= 0; 
    end else begin 
      q <= D;
    end
  end
endmodule
