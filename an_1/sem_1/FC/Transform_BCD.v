module Transform_BCD (
                        input [15:0] Dec_in1, // C1 [-32.767, 32.767] => 15b + 1b(sign) = 16b
                        output reg [19:0] BCD_out // abs(Dec_in1) in BCD
                      );
                  
                  
  reg [15:0] aux;    
                    
  always @(Dec_in1) begin
    aux = 16'b0;
    BCD_out = 20'b0;
    
    if (Dec_in1[15])
      aux[14:0] = ~Dec_in1[14:0];
    else
      aux[14:0] = Dec_in1[14:0];
      
    BCD_out[3:0] = aux % 10;
    aux = aux / 10;
    
    BCD_out[7:4] = aux % 10;
    aux = aux / 10;
    
    BCD_out[11:8] = aux % 10;
    aux = aux / 10;
    
    BCD_out[15:12] = aux % 10;
    aux = aux / 10;
    
    BCD_out[19:16] = aux % 10;
    
  end
endmodule