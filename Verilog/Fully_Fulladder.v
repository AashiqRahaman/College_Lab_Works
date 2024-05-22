module fullAdder(
    input a, b, cin,
    output s, cout
);
    assign s = a ^ b ^ cin;
    assign cout = (a & b) | (b & cin) | (a & cin);
endmodule

module rippleCA(
    input cin,
    input [7:0] a, b,
    output [7:0] s,
    output cout
);
    wire [6:0] conn;
    genvar i;
    generate
        for (i = 0; i < 8; i = i + 1) begin: fullAdder_loop
            if (i == 0)
                fullAdder fa(a[i], b[i], cin, s[i], conn[i]);
            else if (i == 7)
                fullAdder fa(a[i], b[i], conn[i-1], s[i], cout);
            else
                fullAdder fa(a[i], b[i], conn[i-1], s[i], conn[i]);
        end
    endgenerate
endmodule

module mux8b2to1(
    input [7:0] a,
    input s,
    output [7:0] e
);
    assign e = s ? ~a : a;
endmodule

module and8b1(
    input s,
    input [7:0] a,
    output [7:0] e
);
    assign e = s & a;
endmodule

module mux1b4to1(
    input a, b, c, d,
    input s1, s2,
    output e
);
    assign e = (a & ~s1 & ~s2) | (b & ~s1 & s2) | (c & s1 & ~s2) | (d & s1 & s2);
endmodule

module subAdd(
    input [7:0] a, b,
    input cin,
    output [7:0] s,
    output cout
);
    wire [7:0] b2;
    mux8b2to1 mux(b, cin, b2);
    rippleCA dut(cin, a, b2, s, cout);
endmodule

module compliment8bit (
    input [7:0] a,
    output [7:0] b
);
    wire [7:0] onesCom;
    wire waste;
    mux8b2to1 ones(a, 1'b1, onesCom);
    rippleCA twos(1'b1, onesCom, 8'b0, b, waste);
endmodule

module and8bit(
    input [7:0] a, b,
    output [7:0] out
);
    assign out = a & b;
endmodule

module or8bit(
    input [7:0] a, b,
    output [7:0] out
);
    assign out = a | b;
endmodule

module nand8bit(
    input [7:0] a, b,
    output [7:0] out
);
    assign out = ~(a & b);
endmodule

module nor8bit(
    input [7:0] a, b,
    output [7:0] out
);
    assign out = ~(a | b);
endmodule

module not8bit(
    input [7:0] a, b,
    input bitselect,
    output [7:0] out
);
    assign out = bitselect ? ~b : ~a;
endmodule

module xor8bit(
    input [7:0] a, b,
    output [7:0] out
);
    assign out = a ^ b;
endmodule

module mux8bit16to1 (
    input [3:0] s,
    input [7:0] inp1, inp2, inp3, inp4, inp5, inp6, inp7, inp8, inp9, inp10, inp11, inp12, inp13, inp14, inp15, inp16,
    output [7:0] out
);
    wire [7:0] inputs [15:0];
    assign inputs[0] = inp1, inputs[1] = inp2, inputs[2] = inp3, inputs[3] = inp4;
    assign inputs[4] = inp5, inputs[5] = inp6, inputs[6] = inp7, inputs[7] = inp8;
    assign inputs[8] = inp9, inputs[9] = inp10, inputs[10] = inp11, inputs[11] = inp12;
    assign inputs[12] = inp13, inputs[13] = inp14, inputs[14] = inp15, inputs[15] = inp16;
    assign out = inputs[s];
endmodule

module alu(
    input [3:0] command,
    input [7:0] a, b,
    output [7:0] out,
    output carry
);
    wire [7:0] inp[0:15];
    wire carry1, carry2, carry3, carry4;
    reg add = 1'b0, sub = 1'b1;
    wire carry_select1 = ~command[2] & ~command[1], carry_select2 = command[3] & ~command[2];

    subAdd addd(a, b, add, inp[0], carry1);
    subAdd subb(a, b, sub, inp[1], carry2);
    and8bit andd(a, b, inp[2]);
    or8bit orr(a, b, inp[3]);
    nand8bit nandd(a, b, inp[4]);
    xor8bit xorr(a, b, inp[5]);
    nor8bit norr(a, b, inp[6]);
    not8bit nott(a, b, command[3], inp[7]);

    compliment8bit rebornBBB(b, inp[8]);

    subAdd add1(a, inp[8], add, inp[9], carry3);
    subAdd sub1(a, inp[8], sub, inp[10], carry4);
    and8bit andd1(a, inp[8], inp[11]);
    or8bit orr1(a, inp[8], inp[12]);
    nand8bit nandd1(a, inp[8], inp[13]);
    xor8bit xorr1(a, inp[8], inp[14]);
    nor8bit norr1(a, inp[8], inp[15]);

    mux8bit16to1 joke(command, inp[0], inp[1], inp[2], inp[3], inp[4], inp[5], inp[6], inp[7], inp[8], inp[9], inp[10], inp[11], inp[12], inp[13], inp[14], inp[15], out);
    mux1b4to1 joke2(carry1, carry2, carry3, carry4, carry_select1, carry_select2, carry);
endmodule

module tb_alu;
    reg [3:0] command;
    reg [7:0] a, b;
    wire [7:0] out;
    wire carry;

    alu dut(command, a, b, out, carry);

    initial begin
        $monitor($time,,,"command = %b, opA = %b, opB = %b, Res = %b, carry/borrow = %b", command, a, b, out, carry);
        command = 4'b0000; a = 8'b00101010; b = 8'b11111111;
        #5 command = 4'b0001;
        #5 command = 4'b0010;
        #5 command = 4'b0011;
        #5 command = 4'b0100;
        #5 command = 4'b0101;
        #5 command = 4'b0110;
        #5 command = 4'b0111;
        #5 command = 4'b1000;
        #5 command = 4'b1001;
        #5 command = 4'b1010;
        #5 command = 4'b1011;
        #5 command = 4'b1100;
        #5 command = 4'b1101;
        #5 command = 4'b1110;
        #5 command = 4'b1111;
        #5 $finish;
    end
endmodule