module test_tb;
  reg a_tb, b_tb;
  wire w_tb, x_tb, y_tb, z_tb;
  
  // monitor
  initial begin
    $monitor("Time=%d a=%b b=%b w=%b x=%b y=%b z=%b",
              $time, a_tb, b_tb, w_tb, x_tb, y_tb, z_tb);
  end
  
  // generare stimuli
  initial begin
    a_tb = 1; 
    b_tb = 1;
    #1 a_tb = 0;
    #1 b_tb = 0;
    #1;
  end
  
  // instantiere DUT
  test instantiereDUT (
                      .a(a_tb),
                      .b(b_tb),
                      .w(w_tb),
                      .x(x_tb),
                      .y(y_tb),
                      .z(z_tb)
                    );
endmodule
  
