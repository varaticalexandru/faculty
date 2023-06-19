-- Să se listeze toți studenții care au cursuri în ziua de 
-- ’Luni’

select
    s.sid, s.cnp, s.nume, c.cid, c.titlu, c.zi
from
    student s join contract ctr on s.sid = ctr.sid
    join curs c on ctr.cid = c.cid
where
    c.zi = 'Luni'