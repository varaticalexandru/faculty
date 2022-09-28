module ierdna (
                input aral, atac, ide, icul,
                output reg anao, anaid, luap
              );
              
  always @(ide or icul) begin
    if (aral == 0)
      anao = icul + atac;
    else if (aral == 1)
      anao = ide - atac;
      
    if ((icul == 0) && (aral == 1))
      anaid = atac*icul;
    else
      anaid = atac/icul;
      
    luap = aral + atac + ide + icul;
  end
  
endmodule
    
