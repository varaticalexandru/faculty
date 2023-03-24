-- Folosind subinterogări (fără a folosi join) să se 
-- afișeze toate cursurile care se țin într-o sală cu mai mult de 100 
-- de locuri.

SELECT c.cid, c.titlu, c.fid, c.sala
FROM Curs c
WHERE c.sala in

(SELECT s.cods
FROM Sala s
WHERE s.nr_locuri > 100
);


