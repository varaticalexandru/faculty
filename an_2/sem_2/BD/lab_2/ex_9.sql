-- Se consideră studenții împărțiți în două grupuri – fete 
-- și respectiv băieți. Să se afișeze toți studenți afișând numele, anul 
-- de studiu și grupul (fete sau băieți) din care fac parte

select
    nume, an,
    case
        when substr(cnp, 0, 1)=2 or substr(cnp, 0, 1)=4 or substr(cnp, 0, 1)=6 or substr(cnp, 0, 1)=8 then 'F'
        else 'M'
    end as grup
from
    student s