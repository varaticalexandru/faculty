-- fara operatii pe multimi

select 
    s.sid, s.nume, s.an, s.bursa
from
    student s
where
    (s.bursa < 750 or s.bursa > 900) and s.bursa is not null and s.bursa > 0