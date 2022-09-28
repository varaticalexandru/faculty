/* Adaugati si fisierul tests_mult.dat in proiect pentru a se putea testa */

module Multiply_4_bit_tb();
  reg[3:0] X_tb, Y_tb;
  reg clk_tb, start_tb;
  reg[7:0] P_tb_exp;
  wire[7:0] P_tb_actual;
  wire stop_tb;

  Multiply_4_bit DUT(.X(X_tb), .Y(Y_tb), .clk(clk_tb), .start(start_tb), .stop(stop_tb), .P(P_tb_actual));
  
  integer data_file, n_tests, n_tests_passed, timeout_count;
  reg all_tests_finished, single_test_started; 
  reg aString;

  initial begin
    n_tests = 0;
    n_tests_passed = 0;
    data_file = $fopen("tests_mult.dat", "r");
    if (data_file == 0) begin
      $display("Adauga fisierul tests_mult.dat in acelasi proiect");
      $finish;
    end
    /* ignoram prima linie */
    $fscanf(data_file, "%s %s %s\n", aString, aString, aString);
    
    all_tests_finished = 0;
    single_test_started = 0;
    
    clk_tb = 1'b1;
    while(!all_tests_finished) begin
      #1 clk_tb = ~clk_tb;
    end
  end
  
  always @(clk_tb) begin
    /* Daca nu s-a ajuns la finalul testului SAU s-a inceput ultimul test */
    if(!$feof(data_file) || single_test_started) begin
      if(!single_test_started) begin
        /* Testul nu a inceput inca. Inseamna ca ori suntem la primul test ori testul precedent s-a terminat. Se poate incepe alt test */
        $fscanf(data_file, "%d %d %d", X_tb, Y_tb, P_tb_exp);
        start_tb = 1'b1;
        #2; //Asteptam sa fie recunoscuta intrarea start_tb
        single_test_started = 1'b1;
        timeout_count = 0;
        n_tests = n_tests + 1;
        $display("[Test %d]", n_tests);
      end
      else begin
        /* Testul a inceput deja. Asteptam sa se finalizeze inainte sa verificam. Ne folosim de iesirea stop */
        start_tb = 1'b0;
        #2;
        if(stop_tb == 1'b1) begin // Daca s-a terminat testul, putem verifica rezultatul
          $display("Pentru intrarile X = %d  Y = %d", X_tb, Y_tb);
          $display("Rezultatul asteptat este P = %d", P_tb_exp);
          // Asteptam sa dam sansa modulului de inmultire sa updateze iesirea
          single_test_started = 1'b0;
          if(P_tb_exp == P_tb_actual) begin
            $display("Test PASSED");
            n_tests_passed = n_tests_passed + 1;
          end
          else begin
            $display("Test FAILED");
            $display("Rezultatul actual P_tb = %d", P_tb_actual);
          end
        end else begin
          timeout_count = timeout_count + 1;
          if(timeout_count == 50) begin // Nu ar trebui sa dureze mai mult de 20 de tacturi de clk
            $display("Testul a durat prea mult! Aborting..");
            $finish;
          end
        end
      end
    end else begin
      /* S-a ajuns la finalul fisierului. S-au terminat toate testele */
      all_tests_finished = 1'b1;
      $display("Teste passed: %d / %d", n_tests_passed, n_tests);
    end
  end
endmodule
            
            
            