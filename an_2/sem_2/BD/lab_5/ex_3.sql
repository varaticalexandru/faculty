-- Folosind subinterogări (fără a folosi join) să se 
-- afișeze toate cursurile care se țin într-o sală cu mai mult de 100 
-- de locuri.

select
    c.cid, c.titlu, c.fid, c.an, c.sala
from
    curs c
where
    c.sala not in
    (select cods from sala where nr_locuri <= 100)


