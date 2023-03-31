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