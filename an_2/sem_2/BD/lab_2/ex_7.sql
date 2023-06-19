-- Să se afișeze toți studenții din anul 2. Se va afișa 
-- numele, anul si CNP-ul. Pentru studenții care nu au completat 
-- CNP-ul se va afișa ‘CNP necompletat’.

select
    nume,
    an,
    case
        when cnp is null then 'CNP necompletat'
        else cnp
    end as CNP
from
    student s
where
    an = 2