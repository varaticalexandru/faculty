module Transform2_tb();
  reg [10:0] C2_in_tb;
  wire [15:0] E3_out_tb;
  wire Sign_tb;
  
  // instantiere DUT
  Transform2 instance_name (
              .C2_in(C2_in_tb),
              .E3_out(E3_out_tb),
              .Sign(Sign_tb)
              );
              
              
  // generare stimuli
  initial begin
    C2_in_tb = 11'b11001101111; // -623
    
  end
  
  // afisare
  initial begin
    $monitor("time = %b | C2_in = %b | E3_out = %b | Sign = %b",
              $time, C2_in_tb, E3_out_tb, Sign_tb);
  end
endmodule