module circuit_simplu_tb();
  reg a, b;
  wire c, c_ideal;
  
  
  circuit_simplu tb(
                    .a(a),
                    .b(b),
                    .c(c),
                    .c_ideal(c_ideal)
                  );
  reg [1:0] aux;
  initial begin
    for (aux = 0; aux <= 3; aux = aux + 1)
      #1 {a,b} = aux;
  end
endmodule