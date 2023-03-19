SELECT s.sid, s.nume, s.an, f.nume as facultate
FROM Student s, Facultate f
WHERE s.fid = f.fid AND an < 3;


