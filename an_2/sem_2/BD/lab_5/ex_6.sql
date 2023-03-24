-- Folosind operatorul EXISTS să se listeze facultățile
-- (fid și nume) care au cel puțin un student cu bursa cea mai mare 
-- posibilă în universitate. (Obs.: Se pot utiliza două sau mai multe 
-- subinterogări succesive imbricate)

SELECT f.fid, f.nume
FROM Facultate f
WHERE

EXISTS
(
    SELECT s.nume, s.bursa
    FROM Student s
    WHERE s.bursa = 

    (SELECT distinct bursa as bursa_minima
    FROM
    (
    SELECT s.sid, s.nume, s.bursa
    FROM Student s
    WHERE s.bursa >= ALL
    (SELECT bursa
    FROM Student
    WHERE bursa IS NOT NULL AND bursa > 0)
    )
    WHERE bursa > 0)
)