-- Cursurile care nu se desfășoară la etajul 1

SELECT c.titlu, c.an, c.sala
FROM Curs c
WHERE c.sala NOT IN
(SELECT cods
FROM Sala
WHERE etaj = 1)
