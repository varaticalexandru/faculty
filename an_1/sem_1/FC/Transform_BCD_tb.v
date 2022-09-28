module Transform_BCD_tb();
  reg [15:0] Dec_in1_tb;
  wire [19:0] BCD_out_tb;
  
  // instantiere DUT
  Transform_BCD obj (
                      .Dec_in1(Dec_in1_tb),
                      .BCD_out(BCD_out_tb)
                    );
  
  // generare stimuli
  initial begin
    #1 Dec_in1_tb = 16'b1111_1111_1111_1111;  // 0
    #1 Dec_in1_tb = 16'b0000_0100_1101_0010;  // 1.234
    #3 Dec_in1_tb = 16'b1111_1101_1111_0110;  // -521
    #1 Dec_in1_tb = 16'b1000_0000_0000_0000;  // -32.767
    #2 Dec_in1_tb = 16'b1000_0000_0000_0000;  // -32.767
  end
  
  // afisare
  initial begin
    $monitor("time = %b | Dec_in1 = %b | BCD_out = %b",
              $time, Dec_in1_tb, BCD_out_tb);
  end
endmodule
