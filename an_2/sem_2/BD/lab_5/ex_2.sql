-- să se afișeze valoarea bursei 
-- minime la facultatea AC

SELECT distinct bursa as bursa_minima
FROM
(
SELECT s.sid, s.nume, s.bursa
FROM Student s
WHERE s.bursa <= ALL
(SELECT bursa
FROM Student
WHERE bursa IS NOT NULL AND bursa > 0)
)
WHERE bursa > 0


-- să se afișeze valoarea bursei 
-- minime la facultatea AC

SELECT distinct bursa as bursa_minima
FROM
(
SELECT s.sid, s.nume, s.bursa
FROM Student s
WHERE s.bursa <= ALL
(SELECT bursa
FROM Student
WHERE bursa IS NOT NULL AND bursa > 0)
)
WHERE bursa > 0