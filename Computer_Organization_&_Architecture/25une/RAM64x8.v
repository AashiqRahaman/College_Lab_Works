module ram_64x8 (
    input wire clk,            
    input wire wr,             
    input wire [5:0] address,  
    input wire [7:0] din,      
    output reg [7:0] data    
);

    reg [7:0] ram [0:63];
    always @(posedge clk) begin
        if (wr) begin
            ram[address] <= din;
        end
        data <= ram[address];
    end
endmodule
module tb_ram_64x8;
    reg clk;
    reg wr;
    reg [5:0] address;
    reg [7:0] din;
    wire [7:0] data;

    ram_64x8 DUT (
        .clk(clk),
        .wr(wr),
        .address(address),
        .din(din),
        .data(data)
    );

    initial begin
        clk = 0;
        wr = 0;
        address = 0;
        din = 8'h00;
        $monitor("At time %0t, clk = %b, address = %h, din = %h, data = %h", $time, clk, address, din, data);

        wr = 1;
        #10;
        address = 6'h00;
        din = 8'h11;
        #10;
        address = 6'h01;
        din = 8'h22;
        #10;
        address = 6'h02;
        din = 8'h33;
        #10;
        
        wr = 0; 
        #10;
        address = 6'h00;
        #10;
        address = 6'h01;
        #10;
        address = 6'h02;
        #10;
        #10 $finish;
    end
    always #5 clk = ~clk;
endmodule

