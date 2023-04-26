-- Să se afișeze bursa minimă (>0), medie și maximă a 
-- tuturor studenților care au ore in ziua de 'Luni', indiferent de curs.


SELECT 
MIN(distinct bursa) as minBursa,
MAX(distinct bursa) as maxBursa,
trunc(AVG(distinct bursa), 2) as avgBursa

FROM Student s

JOIN 
Contract ctr ON ctr.sid = s.sid

JOIN
Curs c ON c.cid = ctr.cid

WHERE c.zi = 'Luni';