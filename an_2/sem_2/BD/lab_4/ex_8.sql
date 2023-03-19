-- Să se listeze toți studenții care au cursuri în ziua de 
-- ’Luni’

SELECT s.nume as nume_student, c.titlu as titlu_curs, c.zi as zi_curs
FROM 

Contract ctr JOIN Curs c 
ON ctr.cid = c.cid

FULL JOIN Student s
ON ctr.sid = s.sid

WHERE c.zi = 'Luni';