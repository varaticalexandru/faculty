module test1_tb  ; 
 
        reg [15:0] a_tb;
        reg [15:0] b_tb;
        reg [7:0] c_tb;
        reg en_tb;
        wire [7:0] x_tb;
        wire [7:0] y_tb;
        wire [3:0] z_tb;
        wire w_tb;
  
  // monitor
  initial begin
    $monitor("Time=%d a=%b b=%b c=%b en=%b",
              $time, a_tb, b_tb, c_tb, en_tb);
  end
    
  
  
  // generare stimuli
  initial begin
    a = 16'hAB;
    b = 16b'11000011;
    c = 8b'00000101;
    en = 0;
    
    a = 16'hAB;
    b = 8b'11111100;
    c = 00000010;
    en = 1;
    
  
  
  // instantiere DUT
  test1  
   DUT  ( 
       .x (x_tb) ,
      .y (y_tb) ,
      .a (a_tb) ,
      .z (z_tb) ,
      .b (b_tb) ,
      .w (w_tb) ,
      .en (en_tb) ,
      .c (c_tb)
      ); 

endmodule

