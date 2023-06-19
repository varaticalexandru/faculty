-- Să se listeze toate sălile, împreună cu numărul de 
-- locuri, care sunt folosite și de facultatea MEC și de cea AC
-- pentru cursuri la aceste facultăți.

select
    s.cods, s.etaj, s.nr_locuri
from
    sala s
where
    s.cods in
    (select sala from curs where fid = 'AC')
    and
    s.cods in
    (select sala from curs where fid = 'MEC')