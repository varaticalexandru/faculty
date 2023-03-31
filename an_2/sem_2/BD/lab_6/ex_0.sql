SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa < 750

UNION

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa > 900


-----------------------

-- facultatile care au cursuri si luni, si miercuri

SELECT f.fid
FROM Facultate f
JOIN 
Curs c ON c.fid = f.fid
WHERE c.zi = 'Luni'

INTERSECT

SELECT f.fid
FROM Facultate f
JOIN 
Curs c ON c.fid = f.fid
WHERE c.zi = 'Miercuri';


-- facultatile care au cursuri si luni, si miercuri (v2)

SELECT c.fid 
FROM Curs c
WHERE c.zi = 'Luni'

INTERSECT

SELECT c.fid
FROM  Curs c
WHERE c.zi = 'Miercuri';