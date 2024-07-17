module rom_64x8 (
    input wire [5:0] address, 
    output reg [7:0] data     
);

    reg [7:0] rom [63:0]; 

    initial begin
        rom[0]  = 8'h00;
        rom[1]  = 8'h01;
        rom[2]  = 8'h02;
        rom[3]  = 8'h03;
        rom[4]  = 8'h04;
        rom[5]  = 8'h05;
        rom[6]  = 8'h06;
        rom[7]  = 8'h07;
        rom[8]  = 8'h08;
        rom[9]  = 8'h09;
        rom[10] = 8'h0A;
        rom[11] = 8'h0B;
        rom[12] = 8'h0C;
        rom[13] = 8'h0D;
        rom[14] = 8'h0E;
        rom[15] = 8'h0F;
        rom[16] = 8'h10;
        rom[17] = 8'h11;
        rom[18] = 8'h12;
        rom[19] = 8'h13;
        rom[20] = 8'h14;
        rom[21] = 8'h15;
        rom[22] = 8'h16;
        rom[23] = 8'h17;
        rom[24] = 8'h18;
        rom[25] = 8'h19;
        rom[26] = 8'h1A;
        rom[27] = 8'h1B;
        rom[28] = 8'h1C;
        rom[29] = 8'h1D;
        rom[30] = 8'h1E;
        rom[31] = 8'h1F;
        rom[32] = 8'h20;
        rom[33] = 8'h21;
        rom[34] = 8'h22;
        rom[35] = 8'h23;
        rom[36] = 8'h24;
        rom[37] = 8'h25;
        rom[38] = 8'h26;
        rom[39] = 8'h27;
        rom[40] = 8'h28;
        rom[41] = 8'h29;
        rom[42] = 8'h2A;
        rom[43] = 8'h2B;
        rom[44] = 8'h2C;
        rom[45] = 8'h2D;
        rom[46] = 8'h2E;
        rom[47] = 8'h2F;
        rom[48] = 8'h30;
        rom[49] = 8'h31;
        rom[50] = 8'h32;
        rom[51] = 8'h33;
        rom[52] = 8'h34;
        rom[53] = 8'h35;
        rom[54] = 8'h36;
        rom[55] = 8'h37;
        rom[56] = 8'h38;
        rom[57] = 8'h39;
        rom[58] = 8'h3A;
        rom[59] = 8'h3B;
        rom[60] = 8'h3C;
        rom[61] = 8'h3D;
        rom[62] = 8'h3E;
        rom[63] = 8'h3F;
    end

    always @(*) begin
        data = rom[address];
    end

endmodule

module tb_rom_64x8;

    reg [5:0] address;      
    wire [7:0] data;        

    rom_64x8 uut (
        .address(address),
        .data(data)
    );

    initial begin

        address = 6'd0; #10; 

        
        address = 6'd1; #10;
        address = 6'd2; #10;
        address = 6'd3; #10;
        address = 6'd4; #10;
        address = 6'd5; #10;
        address = 6'd6; #10;
        address = 6'd7; #10;
        address = 6'd8; #10;
        address = 6'd9; #10;
        address = 6'd10; #10;
        address = 6'd11; #10;
        address = 6'd12; #10;
        address = 6'd13; #10;
        address = 6'd14; #10;
        address = 6'd15; #10;
        address = 6'd63; #10; 
        
        $finish; 
    end

    initial begin

        $monitor("At time %t, Address = %d, Data = %h", $time, address, data);
    end

endmodule