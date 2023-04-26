SELECT
COUNT(*) AS nrStud,
COUNT(bursa) AS nrBurse,
COUNT(DISTINCT bursa) AS nrNiveluriBurse
FROM Student;


-- Nivelurile minime si maxime ale burselor
SELECT
MIN(bursa) as bursaMin,
MAX(bursa) as bursaMax
FROM Student
WHERE bursa > 0;


-- varianta si interval de normalitate [m1, m2] a mediilor
SELECT 
trunc(variance(media), 2) AS varianta,
trunc(avg(media), 2) - trunc(stddev(media), 2) AS m1,
trunc(avg(media), 2) + trunc(stddev(media), 2) AS m2
FROM Student;


SELECT an AS anStudiu,
COUNT(*) AS nrStudAn
FROM Student
GROUP BY an
HAVING COUNT(*) > 3;