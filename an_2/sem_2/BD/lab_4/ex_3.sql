-- Să se listeze toate cursurile care se țin la etajul 1 (în
-- orice sală de la etajul 1)

select
    cid, titlu, fid, an, zi, ora, sala, s.etaj
from
    curs c left join sala s on c.sala = s.cods
where
    s.etaj = 1