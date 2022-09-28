module lab5_tb();
  reg in[7:0], in_tb;
  wire a_tb,b_tb,c_tb,d_tb;
  
  // monitor
  initial begin
    $monitor("Time = %d a = %b b = %b c = %b d = %b", $time,a_tb,b_tb,c_tb,d_tb);
  end
  
  // generare stimuli
  initial begin
    #1 in_tb = 8'b11110000;
    #1 in_tb = 8'b1010101010;
  end
    
  
  // instantiere DUT
  lab5 aRandomName (
        .in(in_tb),
        .a(a_tb),
        .b(b_tb),
        .c(c_tb),
        .d(d_tb)
                    );
                    
endmodule