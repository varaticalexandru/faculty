-- Studenții care au bursa mai mare decât cel cu sid = ‘SET001’

SELECT s.sid, s.nume, s.an, s.bursa
FROM Student s
WHERE s.bursa >
(SELECT bursa FROM Student WHERE sid = 'SET001')