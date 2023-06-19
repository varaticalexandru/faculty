-- să se afișeze valoarea bursei 
-- minime la facultatea AC

select
    distinct bursa as bursa_minima
from
    student s
where
    bursa <= all
    (select bursa from student where bursa is not null and bursa > 0) 
    and
    bursa > 0