module Transform2(
                  input [10:0] C2_in,  // C2 [-1024; 1023] => 10b + 1b (sign) = 11b
                  output reg [15:0] E3_out, // abs(C2_in) in E3
                  output reg Sign   // semnul C2_in
                );
                
  // intervalul maxim de numere pe care il poate acoperi E3: [0; 9999]
  // C2 -> decimal (valoare absoluta) -> E3
  
  integer int;
  reg [9:0] aux;
               
  always @(C2_in) begin
    
    aux = C2_in[9:0];
    
    if (C2_in[10]) begin
      aux = -aux-1;
      Sign = 1;
    end
    else
      Sign = 0;
    
    int = aux;
    $display("int = %d", aux);
    $display("aux = %b", aux);
    
    E3_out[3:0] = (int % 10); //+ 4'b0011
    int = int / 10;
    
    E3_out[7:4] = (int % 10); //+ 4'b0011
    int = int / 10;
    
    E3_out[11:8] = (int % 10); //+ 4'b0011
    int = int / 10;
    
    E3_out[15:12] = (int % 10); //+ 4'b0011
    
  end
endmodule                
