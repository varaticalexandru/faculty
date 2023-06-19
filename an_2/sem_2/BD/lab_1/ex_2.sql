-- Folosind comanda INSERT să se adauge un Contract
-- nou pentru:
-- - studenta ”Elisabeta Maris” la cursul ”Sisteme electrice”
-- - studentul ”Vasile Luca” la cursul ”Sisteme electrice”
-- - studentul ”Carol Jinca” la cursul ”Echipamente electrice”

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
