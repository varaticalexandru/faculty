module lab5_a_tb();
  reg input in_tb[7:0];
  wire output a_tb;
  
  // monitor
  initial begin
    $monitor("time = %d in = %b a = %b", $time,in_tb,a_tb);
  end
  
  // generare stimuli
  initial begin
    #1 in_tb='b11101010;
  end
  
  // instantiere DUT
  lab5_a aRandomName (
                        .in(in_tb),
                        .a(a_tb)
                      );
                    
endmodule
    

