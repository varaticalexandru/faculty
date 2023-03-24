-- studentii cu bursa maxima

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa >= ALL
(SELECT bursa 
FROM Student 
WHERE bursa IS NOT NULL)