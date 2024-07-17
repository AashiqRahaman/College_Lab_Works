module rom_64x8 (    input wire [5:0] address, output reg [7:0] data     );
    reg [7:0] rom [63:0]; 
    integer i;
    initial begin
       for (i = 0; i < 64; i = i + 1) begin
        rom[i] = i;
    end
    end
    always @(*) 
    begin        data = rom[address];    end
endmodule
module tb_rom_64x8;
    reg [5:0] address;      
    wire [7:0] data;        
    rom_64x8 uut (
        .address(address),
        .data(data)
    );
integer i;
    initial begin
    for (i = 0; i < 64; i = i + 1) 
    begin
        address = i;
        #10; 
    end
        $finish; 
    end
    initial begin
        $monitor("At time: %0t, Address = %d, Data = %h", $time, address, data);
    end
endmodule