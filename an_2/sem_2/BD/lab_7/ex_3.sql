-- Să se calculeze numărul total de studenți care au ore 
-- la etajul 1 (încărcarea sălilor de la etajul 1), indiferent de 
-- facultate si de zi

SELECT COUNT(DISTINCT s.sid) AS nrStud
FROM Student s

JOIN
Contract ctr ON ctr.sid = s.sid

JOIN
Curs c ON c.cid = ctr.cid

JOIN
Sala s ON s.cods = c.sala

WHERE s.etaj = 1;