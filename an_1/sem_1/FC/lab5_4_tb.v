module func_4_tb();
  reg a_tb, b_tb;
  wire func_tb;

 // instantiere DUT
 func_4 myAnd (
                      .vect( {a_tb, b_tb} ),
                      .func(func_tb)
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
    #1
    b_tb = 1;
  end

  // monitor
  initial begin
    $monitor("time=%b a=%b b=%b func=%b",
              $time, a_tb, b_tb, func_tb);
  end
  
endmodule
