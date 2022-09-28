module multi_with_a_operatos_tb  ; 
 
  wire  [7:0]  pro   ; 
  reg  [3:0]  x   ; 
  reg  [3:0]  y   ; 
  multi_with_a_operatos  
   DUT  ( 
       .pro (pro ) ,
      .x (x ) ,
      .y (y ) ); 

initial begin 
  x = 4'hF;
  y = 4'hF;
end 

endmodule

