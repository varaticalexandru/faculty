-- Considerând că toți studenții au un singur prenume, 
-- să se afișeze o lista cu numele de familie, prenumele și anul de 
-- studiu a tuturor studenților.

SELECT an, nume,
    CASE WHEN 1 = 1 THEN '-'
    END
    AS prenume
FROM Student;