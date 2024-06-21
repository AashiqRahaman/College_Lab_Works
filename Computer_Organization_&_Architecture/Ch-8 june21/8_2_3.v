module fsm1_behavioral_onehot(
    output reg Dout,
    input wire Clock, Reset, Din
);
    // State encoding
    parameter Start = 3'b001, Midway = 3'b010, Done = 3'b100;
    reg [2:0] current_state, next_state;

    // Next state logic
    always @ (posedge Clock or posedge Reset) begin
        if (Reset)
            current_state <= Start;
        else
            current_state <= next_state;
    end

    // State transition logic
    always @ (*) begin
        case (current_state)
            Start: begin
                if (Din)
                    next_state = Midway;
                else
                    next_state = Start;
                Dout = 0;
            end
            Midway: begin
                if (Din)
                    next_state = Done;
                else
                    next_state = Midway;
                Dout = 0;
            end
            Done: begin
                next_state = Done;
                Dout = 1;
            end
            default: begin
                next_state = Start;
                Dout = 0;
            end
        endcase
    end
endmodule
