module fsm2_behavioral(
    output reg Dout,
    input wire Clock, Reset, Din
);
    // State encoding
    parameter S0 = 2'b00, S1 = 2'b01, S2 = 2'b10, S3 = 2'b11;
    reg [1:0] current_state, next_state;

    // Next state logic
    always @ (posedge Clock or posedge Reset) begin
        if (Reset)
            current_state <= S0;
        else
            current_state <= next_state;
    end

    // State transition logic
    always @ (*) begin
        case (current_state)
            S0: begin
                if (Din)
                    next_state = S1;
                else
                    next_state = S0;
                Dout = 0;
            end
            S1: begin
                if (Din)
                    next_state = S1;
                else
                    next_state = S2;
                Dout = 0;
            end
            S2: begin
                if (Din)
                    next_state = S3;
                else
                    next_state = S0;
                Dout = 0;
            end
            S3: begin
                if (Din)
                    next_state = S1;
                else
                    next_state = S2;
                Dout = 1;
            end
            default: begin
                next_state = S0;
                Dout = 0;
            end
        endcase
    end
endmodule
