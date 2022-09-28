module add_acc_b_tb  ; 
 
  reg  [4:0]  b   ; 
  reg    clk   ; 
  reg    start   ; 
  wire  [4:0]  s   ; 
  reg  [4:0]  acc   ; 
  reg    en   ; 
  
  add_acc_b  
   DUT  ( 
       .b (b ) ,
      .clk (clk ) ,
      .start (start ) ,
      .s (s ) ,
      .acc (acc ) ,
      .en (en ) ); 
      
  initial begin
    clk = 0;
    clk = ~clk; 
    start = 0; 
    b = 5'b01101;
    en = 1;
    acc = 5'b00110; 
  end

endmodule

