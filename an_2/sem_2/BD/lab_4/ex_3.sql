-- Să se listeze toate cursurile care se țin la etajul 1 (în
-- orice sală de la etajul 1)

SELECT c.titlu as titlu_curs, s.etaj 
FROM curs c, sala s
WHERE s.etaj = 1;