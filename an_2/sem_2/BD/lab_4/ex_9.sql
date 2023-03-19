-- Să se listeze toți studenții care au cursuri într-o sală
-- cu mai puțin de 200 de locuri indiferent de zi, ordonați după anul 
-- nașterii și nume


SELECT s.nume as nume_student, c.titlu as titlu_curs, c.sala as sala_curs, sl.nr_locuri
FROM 

Contract ctr JOIN Curs c 
ON ctr.cid = c.cid

JOIN Student s
ON ctr.sid = s.sid

JOIN Sala sl
ON c.sala = sl.cods

WHERE sl.nr_locuri < 200

ORDER BY s.an, s.nume;