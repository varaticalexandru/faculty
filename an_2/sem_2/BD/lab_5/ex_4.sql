-- Să se listeze toate sălile, împreună cu numărul de 
-- locuri, care sunt folosite și de facultatea MEC și de cea AC
-- pentru cursuri la aceste facultăți.

SELECT s.cods, s.nr_locuri
FROM Sala s
WHERE 
s.cods IN
(
SELECT c.sala
FROM Curs c
WHERE c.fid = 'AC'
)
AND s.cods IN
(SELECT c.sala
FROM Curs c
WHERE c.fid = 'MEC');