module func_5_tb();
  reg [1:0] vect_tb;
  wire func_tb;
  
  // instantiere DUT
  func_5 myAnd (
                  .vect(vect_tb),
                  .func(func_tb)
                );
                
  // monitor
  initial begin
    $monitor("time=%b a=%b b=%b func=%b"<
              $time, vect_tb[1], vect_tb[0], func_tb);
  end
  
  // generare stimuli
  initial begin
    vect_tb = 2'b00;
    #1 vect_tb = 2'b01;
    #1 vect_tb = 2'b10;
    #1 vect_tb = 2'b11;
    #1;
  end
endmodule