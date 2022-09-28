module supl_tb  ; 
 
  wire  [8:0]  sum   ; 
  wire  [31:0]  xor0   ; 
  reg  [31:0]  a   ; 
  reg    sw   ; 
  reg  [31:0]  b   ; 
  wire  reg  o   ; 
  reg    en   ; 
  supl  
   DUT  ( 
       .sum (sum ) ,
      .xor0 (xor0 ) ,
      .a (a ) ,
      .sw (sw ) ,
      .b (b ) ,
      .o (o ) ,
      .en (en ) ); 

endmodule

