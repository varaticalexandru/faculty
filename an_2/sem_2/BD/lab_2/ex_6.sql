-- Să se afișeze toți studenții care nu au completat 
-- câmpul bursa (a căror bursă nu se cunoaște). Cu o nouă 
-- interogare afișați apoi studenții care nu au bursă.


SELECT * 
FROM Student
WHERE bursa iS NULL;

SELECT *
FROM Student
WHERE bursa = 0;