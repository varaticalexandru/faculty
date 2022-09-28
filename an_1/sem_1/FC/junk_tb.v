module junk();
  
  reg a_tb, b_tb;
  wire func_tb;
  
  // monitor
  initial begin
    $monitor("@%0d a=%b b=%b func=%b",
              $time, a_tb, b_tb, func_tb);
  end
  
  // instantiere DUT
  junk tb {
            .a(a_tb),
            .b(b_tb),
            .c(c_tb)
          );
          
  // generare stimuli
  initial begin
    a_tb = 0;
    b_tb = 0;
    #1;
    b_tb = 1;
    #1;
    a_tb = 1;
    b_tb = 0;
    #1;
    b_tb = 1;
    #1;
  end
endmodule