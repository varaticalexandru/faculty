-- Să se afișeze data nașterii celui mai tânăr și celui mai 
-- bătrân student din anul 2.

SELECT
MIN(s.datan) AS dataOldest,
MAX(s.datan) AS dataYoungest

FROM Student s

WHERE s.an = 2;