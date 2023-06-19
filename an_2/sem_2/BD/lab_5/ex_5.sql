-- Să se listeze toți studenții unde mai există cel puțin 
-- încă un student care are exact aceiași bursă și exact aceiași 
-- medie, indiferent de facultatea la care sunt înscriși.

select
    s.sid, s.nume, s.bursa, s.media
from
    student s
where
    exists
    (select sid from student where s.sid != sid and s.bursa = bursa and s.media = media)
