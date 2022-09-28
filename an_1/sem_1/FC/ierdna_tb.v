module ierdna_tb;
  
  reg aral_tb, atac_tb, ide_tb, icul_tb;
  wire anao, anaid, luap;
  
  // monitor
  initial begin
    $monitor("Time=%d IN : aral=%b atac=%b ide=%b icul=%b / / OUT : anao=%b anaid=%b luap=%b",
              $time, aral_tb, atac_tb, ide_tb, icul_tb, anao_tb, anaid_tb, luap_tb);
  end
  
  // generare impulsuri
  initial begin
    aral_tb = 0;
    atac_tb = 0;
    ide_tb = 0;
    icul_tb = 0;
    
    #1 aral_tb = 1;
    atac_tb = 1;
    
    #1 aral_tb = 0;
    ide_tb = 1;
    
    #1 aral_tb = 1;
    atac_tb = 1;
    ide_tb = 1;
    icul_tb =1;
    
    #1;
  end
  
  // instantiere DUT
  ierdna instant (
                    .aral(aral_tb),
                    .atac(atac_tb),
                    .ide(ide_tb),
                    .icul(icul_tb),
                    .anao(anao_tb),
                    .anaid(anaid_tb),
                    .luap(luap_tb)
                  );
endmodule
    
    
