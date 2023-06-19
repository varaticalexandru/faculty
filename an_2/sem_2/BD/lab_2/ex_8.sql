-- Să se scrie două interogări SQL, una care listează toți
-- studenții de sex feminin și cealaltă pe cei de sex masculin. Se va 
-- afișa numele, cnp-ul și anul de studiu.

-- sex f
select
    nume, cnp, an
from
    student
where
    substr(cnp, 0, 1)=2 or substr(cnp, 0, 1)=4 or substr(cnp, 0, 1)=6 or substr(cnp, 0, 1)=8

-- sex m
select
    nume, cnp, an
from
    student
where
    substr(cnp, 0, 1)!=2 and substr(cnp, 0, 1)!=4 and substr(cnp, 0, 1)!=6 and substr(cnp, 0, 1)!=8