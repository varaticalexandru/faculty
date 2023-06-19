-- Considerând că toți studenții au un singur prenume, 
-- să se afișeze o lista cu numele de familie, prenumele și anul de 
-- studiu a tuturor studenților

select
    substr(nume, instr(nume, ' ') + 1) as nume,
    substr(nume, 0, instr(nume, ' ')) as prenume,
    an
from
    student s