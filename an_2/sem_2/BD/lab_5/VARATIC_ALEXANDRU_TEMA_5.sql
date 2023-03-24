-- Să se listeze toți studenții de la facultatea AC care au 
-- media mai mica decât studentul cu CNP = 1020608359554.

SELECT s.sid, s.nume, s.fid, s.an, s.bursa
FROM Student s
WHERE s.fid = 'AC' AND s.bursa < ALL
(SELECT cnp
FROM Student
WHERE cnp = '1020608359554');


-- să se afișeze valoarea bursei 
-- minime la facultatea AC

SELECT distinct bursa as bursa_minima
FROM
(
SELECT s.sid, s.nume, s.bursa
FROM Student s
WHERE s.bursa <= ALL
(SELECT bursa
FROM Student
WHERE bursa IS NOT NULL AND bursa > 0)
)
WHERE bursa > 0


-- să se afișeze valoarea bursei 
-- minime la facultatea AC

SELECT distinct bursa as bursa_minima
FROM
(
SELECT s.sid, s.nume, s.bursa
FROM Student s
WHERE s.bursa <= ALL
(SELECT bursa
FROM Student
WHERE bursa IS NOT NULL AND bursa > 0)
)
WHERE bursa > 0



-- Folosind subinterogări (fără a folosi join) să se 
-- afișeze toate cursurile care se țin într-o sală cu mai mult de 100 
-- de locuri.

SELECT c.cid, c.titlu, c.fid, c.sala
FROM Curs c
WHERE c.sala in

(SELECT s.cods
FROM Sala s
WHERE s.nr_locuri > 100
);




-- Să se listeze toate sălile, împreună cu numărul de 
-- locuri, care sunt folosite și de facultatea MEC și de cea AC
-- pentru cursuri la aceste facultăți.

SELECT s.cods, s.nr_locuri
FROM Sala s
WHERE 
s.cods IN
(
SELECT c.sala
FROM Curs c
WHERE c.fid = 'AC'
)
AND s.cods IN
(SELECT c.sala
FROM Curs c
WHERE c.fid = 'MEC');



-- Să se listeze toți studenții unde mai există cel puțin 
-- încă un student care are exact aceiași bursă și exact aceiași 
-- medie, indiferent de facultatea la care sunt înscriși.

SELECT s.sid, s.nume, s.bursa, s.media
FROM Student s

WHERE EXISTS

(SELECT sid
FROM Student
WHERE s.sid != sid AND s.bursa = bursa AND s.media = media);



-- Folosind operatorul EXISTS să se listeze facultățile
-- (fid și nume) care au cel puțin un student cu bursa cea mai mare 
-- posibilă în universitate. (Obs.: Se pot utiliza două sau mai multe 
-- subinterogări succesive imbricate)

SELECT f.fid, f.nume
FROM Facultate f
WHERE

EXISTS
(
    SELECT s.bursa
    FROM Student s
    WHERE s.bursa =

    (SELECT distinct bursa as bursa_minima
    FROM
    (
    SELECT s.sid, s.nume, s.bursa
    FROM Student s
    WHERE s.bursa >= ALL
    (SELECT bursa
    FROM Student
    WHERE bursa IS NOT NULL AND bursa > 0)
    )
    WHERE bursa > 0)

    AND s.fid = f.fid
)