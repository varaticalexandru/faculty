-- Să se afișeze toți studenții din anul 2. Se va afișa 
-- numele, anul si CNP-ul. Pentru studenții care nu au completat 
-- CNP-ul se va afișa ‘CNP necompletat’.

SELECT nume, an,
    CASE WHEN cnp IS NULL THEN 'CNP necompletat'
    ELSE CNP
    END
    as CNP

FROM student
WHERE an = 2;