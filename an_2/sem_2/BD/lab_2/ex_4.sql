-- Să se afișeze toți studenții care au împlinit deja sau 
-- vor împlinii anul acesta 20 de ani. Se va afișa numele, anul si 
-- data nașterii. Anul curent se consideră cel obținut cu SYSDATE. 


select
    nume,
    an,
    datan,
    (extract(year from sysdate) - extract(year from datan)) as varsta

from
    student s

where
    extract(year from sysdate) - extract(year from datan) = 20

order by varsta asc, nume asc