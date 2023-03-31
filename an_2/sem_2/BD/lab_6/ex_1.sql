-- nu include si studentii fara bursa

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa < 750 AND s.bursa IS NOT NULL

UNION

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa > 900 AND s.bursa IS NOT NULL;


-- nu include si studentii fara bursa (v2)

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa < 750 

UNION

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa > 900

EXCEPT

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa IS NULL;