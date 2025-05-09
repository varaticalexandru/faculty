-- Folosind ALTER TABLE sÄƒ se adauge o constrÃ¢ngere
-- la tabela student care sÄƒ verifice cÄƒ anul de studiu este Ã®ntre 1 si 4

alter table student
modify an number(1,0)
check (an <= 4 and an  >= 1);
-- Folosind comanda INSERT sÄƒ se adauge un Contract
-- nou pentru:
-- - studenta â€Elisabeta Marisâ€ la cursul â€Sisteme electriceâ€
-- - studentul â€Vasile Lucaâ€ la cursul â€Sisteme electriceâ€
-- - studentul â€Carol Jincaâ€ la cursul â€Echipamente electriceâ€

insert all
into contract
(nrc, sid, cid, an)
values (
    -- nrc
    11,
    -- sid
    (select sid from student s where s.nume like 'Elisabeta Maris'),
    -- cid
    (select cid from curs c where c.titlu like 'Sisteme electrice'),
    -- an
    (select extract(year from sysdate) from dual)

)

into contract
(nrc, sid, cid, an)
values (
    -- nrc
    12,
    -- sid
    (select sid from student s where s.nume like 'Vasile Luca'),
    -- cid
    (select cid from curs c where c.titlu like 'Sisteme electrice'),
    -- an
    (select extract(year from sysdate) from dual)
)

into contract
(nrc, sid, cid, an)
values (
    -- nr
    13,
    -- sid
    (select s.sid from student s where s.nume like 'Carol Jinca'),
    -- cid
    (select c.cid from curs c where c.titlu like 'Echipamente electrice'),
    -- an
    (select extract(year from sysdate) from dual)
)

select 1 from dual;
-- Folosind comanda UPDATE cu WHERE sÄƒ se 
-- modifice numÄƒrul de locuri din sala A109 la 82

update sala
set nr_locuri = 82
where cods like 'A109';
-- Folosind comanda DELETE cu WHERE sÄƒ se È™teargÄƒ
-- contractul pentru studentul â€Vasile Lucaâ€ la cursul â€Sisteme electriceâ€


delete 
from contract ctr
where 
ctr.sid = (select sid from student where nume like 'Vasile Luca')
AND
ctr.cid = (select cid from curs where titlu like 'Sisteme electrice');
