-- Să se listeze toți studenții a căror prenume este mai 
-- lung de 7 caractere inclusiv. Se va afișa numele complet, 
-- prenumele și lungimea prenumelui pentru verificare.

select
    nume,
    substr(nume, 0, instr(nume, ' ')) as prenume,
    length(substr(nume, 0, instr(nume, ' '))) as lng

from
    student s

where
    length(substr(nume, 0, instr(nume, ' '))) >= 7

order by lng asc, prenume asc