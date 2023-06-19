-- Să se afișeze toți studenții care își serbează ziua de 
-- naștere în luna curentă. 
-- Obs: luna curentă se va obține din 
-- SYSDATE.


select
    sid,
    nume,
    datan,
    extract(month from datan) as luna_nasterii,
    extract(month from sysdate) as luna_curenta

from
    student s

where
    extract(month from datan) = extract(month from sysdate)