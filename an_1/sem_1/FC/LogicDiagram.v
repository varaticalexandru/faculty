module LogicDiagram(
                    input A, B, C,
                    output Q
                    );
                    
  assign Q = (A&B&C) | (A&((~B)|(~C)));       
         
                    
endmodule
