-- Să se listeze toți studenții care au cel puțin un 
-- contract de studii semnat, ordonați după numele de familie (obs. 
-- în BD sunt în format “prenume nume_familie”).


SELECT s.nume, ctr.nrc

FROM
Student s LEFT JOIN Contract ctr
ON ctr.sid = s.sid

WHERE ctr.nrc is not null

ORDER BY substr(s.nume, instr(s.nume, ' ')+1);



select
    s.sid, s.cnp, s.nume, ctr.nrc
from
    student s right join contract ctr on s.sid = ctr.sid
order by
    substr(s.nume, instr(nume, ' ')+1)