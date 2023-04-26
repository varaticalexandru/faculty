-- Să se calculeze suma și media burselor pe fiecare an 
-- de studiu la fiecare facultate. Se vor afișa numele facultății, anul 
-- de studiu, suma și media burselor

SELECT
f.nume,
s.an,
SUM(s.bursa),
AVG(trunc(s.bursa, 2))

FROM Student s

JOIN
Facultate f ON s.fid = f.fid

GROUP BY s.an, f.nume
;