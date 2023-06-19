-- Folosind comanda DELETE cu WHERE să se șteargă
-- contractul pentru studentul ”Vasile Luca” la cursul ”Sisteme electrice”


delete 
from contract ctr
where 
ctr.sid = (select sid from student where nume like 'Vasile Luca')
AND
ctr.cid = (select cid from curs where titlu like 'Sisteme electrice');