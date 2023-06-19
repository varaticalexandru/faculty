-- Să se listeze toți studenții de la facultatea AC care au 
-- media mai mica decât studentul cu CNP = 1020608359554.

select
    s.sid, s.nume, s.an, s.fid
from
    student s
where
    s.fid = 'AC'
    and
    s.media < (select bursa from student where cnp = '1020608359554')