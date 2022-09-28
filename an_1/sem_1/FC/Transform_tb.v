module Transform_tb();
  reg [15:0] BCD_in_tb;
  reg Sign_tb;
  wire [14:0] Out_tb;
  
  // instantiere DUT
  Transform obj (
                  .BCD_in(BCD_in_tb),
                  .Sign(Sign_tb),
                  .Out(Out_tb)
                );
  
  
  // generare stimuli
  initial begin
    BCD_in_tb = 16'b1001_1001_1001_0000;  //  9990
    Sign_tb = 1;
  end
  
  // afisare
  initial begin
    $monitor("time = %b | BCD_in = %b | Sign = %b | Out = %b",
              $time, BCD_in_tb, Sign_tb, Out_tb);
  end
endmodule
