-- ex 1

ALTER TABLE Student
ADD CONSTRAINT CKAN
CHECK (an BETWEEN 1 and 4)


-- ex 2

-- studenta ”Elisabeta Maris” la cursul ”Sisteme electrice”
INSERT INTO Contract(nrc, sid, cid, an, semestru)
VALUES (10, 'SET001', 'CRS03', 2022, 2);

-- - studentul ”Vasile Luca” la cursul ”Sisteme electrice”
INSERT INTO Contract(nrc, sid, cid, an, semestru)
VALUES (11, 'SET002', 'CRS03', 2022, 2);

-- - studentul ”Carol Jinca” la cursul ”Echipamente electrice”
INSERT INTO Contract(nrc, sid, cid, an, semestru)
VALUES (12, 'SET003', 'CRS04', 2022, 2);


-- ex 3

-- Folosind comanda UPDATE cu WHERE să se 
-- modifice numărul de locuri din sala A109 la 82

UPDATE SALA
SET Nr_locuri=82
WHERE cods='A109';


-- ex 4

-- Folosind comanda DELETE cu WHERE să se șteargă
-- contractul pentru studentul ”Vasile Luca” la cursul ”Sisteme 
-- electrice”.


DELETE FROM Contract
WHERE sid='SET002'
