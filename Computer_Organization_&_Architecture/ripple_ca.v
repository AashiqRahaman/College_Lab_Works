
module full_adder(
    input a,b,cin,
    output sum,carry);

assign sum = a ^ b ^ cin;
assign carry = (a & b)|(b & cin)|(cin & a);
                
endmodule

module rca(
    input [3:0]a,b,
    input cin,
    output [3:0]sum,
    output c4);

wire c1,c2,c3;      

full_adder fa0(a[0],b[0],cin,sum[0],c1);
full_adder fa1(a[1],b[1],c1,sum[1],c2);
full_adder fa2(a[2],b[2],c2,sum[2],c3);
full_adder fa3(a[3],b[3],c3,sum[3],c4);
                
endmodule


module rca_tb(
    output  reg [3:0]a,b,
    output reg cin,
    input wire [3:0]sum,
    input wire c4
);

initial begin
$monitor($time,,,  "a = %b, b = %b, cin = %b, sum = %b, c4 = %b", a, b, cin, sum, c4);
            
cin = 0;
a = 4'b0110;
b = 4'b1100;
#10
a = 4'b1110;
b = 4'b1000;
#10
a = 4'b0111;
b = 4'b1110;
#10
a = 4'b0010;
b = 4'b1001;
cin = 1;
a = 4'b0110;
b = 4'b1100;
#10
a = 4'b1110;
b = 4'b1000;
#10
a = 4'b0111;
b = 4'b1110;
#10
a = 4'b0010;
b = 4'b1001;
#10
$finish();
end

endmodule

module rca_wb;
wire [3:0]a,b;
wire cin;
wire [3:0]sum;
wire c4;
    
    initial begin
        $dumpfile("ripple_ca.vcd");
        $dumpvars(0,rca_wb);
    end    
    rca dut(a,b,cin,sum,c4);
    rca_tb tb(a,b,cin,sum,c4);
endmodule