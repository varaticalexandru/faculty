-- Să se calculeze numărul de studenți care nu au bursă 
-- și au media peste 7.50.

SELECT COUNT(*) as nrStud
FROM Student s
WHERE (bursa = 0 OR bursa IS NULL) AND media > 7.50;