-- fara operatii pe multimi

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE (s.bursa < 750 OR s.bursa > 900) AND s.bursa IS NOT NULL