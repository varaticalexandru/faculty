-- Să se listeze toți studenții de la facultatea AC care au 
-- media mai mica decât studentul cu CNP = 1020608359554.

SELECT s.sid, s.nume, s.fid, s.an, s.bursa
FROM Student s
WHERE s.fid = 'AC' AND s.bursa < ALL
(SELECT cnp
FROM Student
WHERE cnp = '1020608359554');