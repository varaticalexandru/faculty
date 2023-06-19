-- Folosind operatorul EXISTS să se listeze facultățile
-- (fid și nume) care au cel puțin un student cu bursa cea mai mare 
-- posibilă în universitate. (Obs.: Se pot utiliza două sau mai multe 
-- subinterogări succesive imbricate)

select
    f.fid, f.nume
from
    facultate f
where
    exists
    (select sid, bursa 
    from student s
    where bursa = 
        (select distinct bursa 
        from student 
        where bursa >= all 
            (select bursa 
            from student 
            where bursa is not null and bursa > 0) 
            and bursa > 0
        )

    and
    s.fid = f.fid
    )