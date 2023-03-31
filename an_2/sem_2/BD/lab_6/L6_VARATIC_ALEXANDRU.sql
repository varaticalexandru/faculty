-- nu include si studentii fara bursa

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa < 750 AND s.bursa IS NOT NULL

UNION

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa > 900 AND s.bursa IS NOT NULL;


-- nu include si studentii fara bursa (v2)

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa < 750 

UNION

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa > 900

EXCEPT

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa IS NULL;

-- fara operatii pe multimi

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE (s.bursa < 750 OR s.bursa > 900) AND s.bursa IS NOT NULL

-- sa se listeze toti studentii care au bursa minima
-- impreuna cu cei care au bursa maxima
-- cei care care au bursa=0 sau NULL, se considera ca nu au bursa

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa <= ALL (SELECT bursa from Student WHERE (bursa IS NOT NULL AND bursa > 0))

UNION

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa >= ALL (SELECT bursa from Student WHERE (bursa is NOT NULL AND bursa > 0))

MINUS

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa = 0 OR s.bursa IS NULL;

-- să se listeze studenții care
-- nu au bursa (0 sau NULL) și au ore în sala A101

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s

JOIN

Contract ctr ON ctr.sid = s.sid

JOIN

Curs c ON c.cid = ctr.cid
WHERE c.sala = 'A101';


-- să se listeze studenții care
-- nu au bursa (0 sau NULL) și au ore în sala A101

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa = 0 OR s.bursa IS NULL

INTERSECT

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s

JOIN

Contract ctr ON ctr.sid = s.sid

JOIN

Curs c ON c.cid = ctr.cid
WHERE c.sala = 'A101';

-- să se listeze studenții (sid, nume, 
-- an, bursa) sunt înscriși facultatea care are numărul de telefon 
-- '0256-403211' și nu au ore cu profesorul Ciprian Porumbescu

-- studentii inscrisi la facultatea cu nr. de telefon '0256-403211'
SELECT s.sid, s.nume, s.fid, s.an, s.bursa
FROM Student s
WHERE s.fid = 

(SELECT f.fid
FROM Facultate f
WHERE f.tel = '0256-403211')

INTERSECT

-- studentii care nu au ore cu Ciprian Porumbescu
SELECT s.sid, s.nume, s.fid, s.an, s.bursa
FROM Student s

JOIN

Contract ctr ON ctr.sid = s.sid

JOIN

Curs c ON c.cid = ctr.cid
WHERE c.pid != (SELECT p.pid FROM Profesor P WHERE p.nume = 'Ciprian Porumbescu')
;