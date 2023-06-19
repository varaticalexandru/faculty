-- Să se listeze studenții cu informații despre cursurile 
-- (titlu si sala) la care au nota mai mică sau egală cu 8.


select
    s.sid, s.cnp, s.nume, ctr.nota, c.titlu, c.sala
from
    student s join contract ctr on s.sid = ctr.sid 
    join curs c on ctr.cid = c.cid
where
    ctr.nota <= 8

