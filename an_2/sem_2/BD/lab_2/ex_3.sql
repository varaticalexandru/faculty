-- Să se listeze toți studenții a căror prenume este mai 
-- lung de 7 caractere inclusiv. Se va afișa numele complet, 
-- prenumele și lungimea prenumelui pentru verificare.


SELECT nume as nume_complet, 
    SUBSTR(nume, 0, INSTR(nume, ' ')) as prenume,
    SUBSTR(nume, INSTR(nume, ' ')) as nume,
    length(SUBSTR(nume, 0, INSTR(nume, ' '))) as lungime_prenume

FROM Student
WHERE length(SUBSTR(nume, 0, INSTR(nume, ' '))) >= 7;