-- Să se calculeze intervalul de normalitate a mediilor 
-- pentru fiecare facultate în parte. Se va afișa numele fiecărei 
-- facultăți precum și pragurile de jos și de sus a intervalului de 
-- normalitate pentru mediile studenților din acea facultate


SELECT
f.fid, f.nume,
AVG(s.media),
trunc(variance(s.media), 2) as varianta,
trunc(avg(s.media), 2) - trunc(stddev(s.media), 2) as m1,
trunc(avg(s.media), 2) + trunc(stddev(s.media), 2) as m2


FROM
Facultate f

JOIN
Student s on f.fid = s.fid

GROUP BY f.nume, f.fid

;


