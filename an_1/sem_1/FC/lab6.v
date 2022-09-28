// iesirea va fi egala cu extinderea intrarii pe 16b
// intrarea e reprezentata in C2

module lab6 (
              input [15:0] in,
              output [31:0] a
            );
        
assign a = {{16{in[15]}}, in}; // il copiem pe in[15] de 16 ori // operator de replicare
    
endmodule
              
