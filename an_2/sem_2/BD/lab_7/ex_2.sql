-- Să se calculeze numărul de studenți care au ore cu 
-- profesorul 'Luca Caragiale'.

SELECT COUNT(s.sid) AS nrStud
FROM Student s

JOIN
Contract ctr ON ctr.sid = s.sid

JOIN
Curs c ON c.cid = ctr.cid

WHERE c.pid = (SELECT pid from Profesor WHERE nume = 'Luca Caragiale')