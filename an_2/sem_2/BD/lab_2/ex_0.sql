-- SELECT sid AS ID_student, nume, an FROM Student;

-- SELECT an FROM Student;

-- SELECT DISTINCT an FROM Student;

-- SELECT * FROM Student;

-- SELECT *
-- FROM Student
-- WHERE sid = 'SET001';

-- SELECT *
-- FROM Student
-- WHERE an = 1;

-- SELECT *
-- FROM Student
-- ORDER BY an;

-- SELECT sid, nume, an, media
-- FROM Student
-- ORDER BY an, media;

-- SELECT * 
-- FROM Student
-- WHERE bursa > 0
-- ORDER BY an, media;

-- SELECT upper('aBsscdC')
-- FROM Dual;

-- SELECT nume, upper(nume) AS numS
-- FROM Student;

-- SELECT sid, nume, an
-- FROM Student
-- WHERE nume LIKE 'N%';

-- SELECT
-- extract(MONTH from SYSDATE)
-- FROM Dual;


-- SELECT nume, media,
--     CASE WHEN media < 5 THEN 'NS'
--          WHEN media < 7 THEN 'S'
--          WHEN media < 10 THEN 'B'
--          ELSE 'FB'
--     END
--     AS calificativ
-- FROM Student;