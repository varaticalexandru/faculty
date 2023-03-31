-- sa se listeze toti studentii care au bursa minima
-- impreuna cu cei care au bursa maxima
-- cei care care au bursa=0 sau NULL, se considera ca nu au bursa

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa <= ALL (SELECT bursa from Student WHERE (bursa IS NOT NULL AND bursa > 0))

UNION

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa >= ALL (SELECT bursa from Student WHERE (bursa is NOT NULL AND bursa > 0))

MINUS

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa = 0 OR s.bursa IS NULL;