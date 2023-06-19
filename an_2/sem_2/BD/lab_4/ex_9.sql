-- Să se listeze toți studenții care au cursuri într-o sală
-- cu mai puțin de 200 de locuri indiferent de zi, ordonați după anul 
-- nașterii și nume


select
    s.sid, s.cnp, s.nume, c.titlu, c.zi, c.sala, s.nr_locuri
from
    student s join contract ctr on s.sid = ctr.sid
    join curs c on ctr.cid = c.cid
    join sala s on c.sala = s.cods
where
    s.nr_locuri < 200
order by
    s.datan, s.nume