-- Să se listeze studenții cu informații despre cursurile 
-- (titlu si sala) la care au nota mai mică sau egală cu 8.


SELECT s.nume, c.titlu, ctr.nota, c.titlu, c.sala
FROM 

Contract ctr JOIN Curs c 
ON ctr.cid = c.cid

FULL JOIN Student s
ON ctr.sid = s.sid

WHERE ctr.nota <= 8;

