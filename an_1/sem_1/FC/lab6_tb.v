module lab6_tb();
  reg [15:0] in_tb;
  wire [31:0] a_tb;
  
  // monitor
  initial begin
    $monitor("time=%d, in=%b, a=%b", $time,in_tb,a_tb);
  end
  
  // generare stimuli
  initial begin
    #1 in_tb = 16'h 1100;
  end
  
  // instantiere DUT
  lab6 aRandomName (
                      .in(in_tb),
                      .a(a_tb)
                    );
endmodule
