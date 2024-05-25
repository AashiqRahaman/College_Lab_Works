
// module reg32 (
//     input wire clk,
//     input wire reset,
//     input wire en,
//     input wire [31:0] d,
//     output reg [31:0] q
// );
//     always @(posedge clk or posedge reset) begin
//         if (reset) begin
//             q <= 32'b0;
//         end else if (en) begin
//             q <= d;
//         end
//     end
// endmodule


module RegX 
(
    output reg [31:0] Reg_Out,
    input Clock,Reset,En,
    input [31:0] Reg_In 

);

always @ (posedge Clock or negedge Reset)
    begain: REGISTER

