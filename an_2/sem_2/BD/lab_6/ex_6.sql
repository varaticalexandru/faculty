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


