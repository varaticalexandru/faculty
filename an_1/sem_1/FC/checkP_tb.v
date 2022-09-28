module checkP_tb; 
 
  reg [2:0] n_tb; 
  wire isP_tb; 
  
  
  initial begin
    $monitor("time=%d n=%b isP=%b", $time,n_tb,isP_tb);
  end
  
  
  initial begin
    n_tb[2:0] = 3'b000;
    #1 n_tb[2:0] = 3'b001;
    #1 n_tb[2:0] = 3'b010;
    #1 n_tb[2:0] = 3'b011;
    #1 n_tb[2:0] = 3'b100;
    #1 n_tb[2:0] = 3'b101;
    #1 n_tb[2:0] = 3'b110;
    #1 n_tb[2:0] = 3'b001;
    #1;
  end
  
  
  checkP  
   DUT  ( 
       .isP (isP_tb ) ,
      .n (n_tb ) ); 

endmodule

