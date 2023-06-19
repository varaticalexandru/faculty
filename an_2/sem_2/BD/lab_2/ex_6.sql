-- Să se afișeze toți studenții care nu au completat 
-- câmpul bursa (a căror bursă nu se cunoaște). Cu o nouă 
-- interogare afișați apoi studenții care nu au bursă.


select
    *
from
    student s
where
    bursa is null


select
    *
from
    student s
where
    bursa = 0