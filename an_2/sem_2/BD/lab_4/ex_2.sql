-- Să se listeze toate cursurile de după amiază (>12:00)
-- împreună cu numărul de locuri ale sălii unde se desfășoară

SELECT c.titlu as titlu_curs, c.ora, s.nr_locuri as nr_locuri_sala
FROM Curs c JOIN Sala s
ON c.sala = s.cods
WHERE c.ora > 12;