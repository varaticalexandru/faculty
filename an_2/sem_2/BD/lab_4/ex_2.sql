-- Să se listeze toate cursurile de după amiază (>12:00)
-- împreună cu numărul de locuri ale sălii unde se desfășoară

select
    cid, titlu, fid, an, zi, ora, sala, s.nr_locuri
from    
    curs c left join sala s on c.sala = s.cods
where
    c.ora > 12