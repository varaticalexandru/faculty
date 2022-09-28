module transform_bcd_ (
                        input [15:0] dec_in1, //-32.767..32.767, scris in CC1, +1bit de semm
                        output reg [19:0] bcd_out // bcd -> 5 tetrade
                      );
                      
  reg aux[15:0]; // copie in
  
  always @(dec_in1) begin
    
    if (dec_in1[15]==0) begin
      // nr pozitive raman la fel
      aux[15:0] = dec_in1[15:0];
    end
    else if (dec_in1[15]==1) begin
      aux = ~(dec_in1);
    end
    
    bcd_out[3:0] = aux%10;
    aux = aux / 10; // scapam de ultima cifra
    bcd_out[7:4] = aux%10; 
    aux = aux / 10;
    bcd_out[11:8] = aux%10;
    aux = aux / 10;
    bcd_out[15:12] = aux % 10;
    aux = aux / 10;
    bcd_out[19:16] = aux % 10;
    
  end
  
endmodule
                        
