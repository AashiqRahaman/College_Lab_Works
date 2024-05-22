// 7.1.2 For a Verilog model of a D-flip-flop with a syn-chronous enable (EN), why is not EN listed in the sensitivity list?

module d_flip_flop (
    input wire clk,  
    input wire reset,
    input wire en,  
    input wire d,   
    output reg q
);

always @(posedge clk) begin
    if (reset) begin
        q <= 1'b0; 
    end else if (en) begin
        q <= d;
    end
end

endmodule
