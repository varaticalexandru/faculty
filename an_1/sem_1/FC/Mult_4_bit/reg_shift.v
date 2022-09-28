// Registru de shiftare 

module reg_shift (
                    input [4:0] acc,    // acumulator
                    input [3:0] q,      // multiplier
                    input clk,          // clock
                    input start,
                    output reg [4:0] o_acc,
                    output reg [3:0] o_q
                  );
reg [8:0] temp;                  
    
    always @(posedge clk) begin 
      if (~start) begin
        temp = {acc, q};
        temp = temp >> 1; 
        o_acc = temp [8:4];
        o_q = temp[3:0];
      end
    end
endmodule
