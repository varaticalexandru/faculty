-- Să se listeze toți studenții care nu au nici un contract 
-- de studii semnat, ordonați după an și nume.

SELECT s.nume, ctr.nrc, s.an, s.nume
FROM

Contract ctr FULL JOIN Student s 
ON ctr.sid = s.sid

WHERE ctr.nrc IS NULL

ORDER BY s.an, s.nume;