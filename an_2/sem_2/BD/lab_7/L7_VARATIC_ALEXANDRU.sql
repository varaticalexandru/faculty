SELECT
COUNT(*) AS nrStud,
COUNT(bursa) AS nrBurse,
COUNT(DISTINCT bursa) AS nrNiveluriBurse
FROM Student;


-- Nivelurile minime si maxime ale burselor
SELECT
MIN(bursa) as bursaMin,
MAX(bursa) as bursaMax
FROM Student
WHERE bursa > 0;


-- varianta si interval de normalitate [m1, m2] a mediilor
SELECT 
trunc(variance(media), 2) AS varianta,
trunc(avg(media), 2) - trunc(stddev(media), 2) AS m1,
trunc(avg(media), 2) + trunc(stddev(media), 2) AS m2
FROM Student;


SELECT an AS anStudiu,
COUNT(*) AS nrStudAn
FROM Student
GROUP BY an
HAVING COUNT(*) > 3;

-- Să se calculeze numărul de studenți care nu au bursă 
-- și au media peste 7.50.

SELECT COUNT(*) as nrStud
FROM Student s
WHERE (bursa = 0 OR bursa IS NULL) AND media > 7.50;


-- Să se calculeze numărul de studenți care au ore cu 
-- profesorul 'Luca Caragiale'.

SELECT COUNT(s.sid) AS nrStud
FROM Student s

JOIN
Contract ctr ON ctr.sid = s.sid

JOIN
Curs c ON c.cid = ctr.cid

WHERE c.pid = (SELECT pid from Profesor WHERE nume = 'Luca Caragiale')


-- Să se calculeze numărul total de studenți care au ore 
-- la etajul 1 (încărcarea sălilor de la etajul 1), indiferent de 
-- facultate si de zi

SELECT COUNT(DISTINCT s.sid) AS nrStud
FROM Student s

JOIN
Contract ctr ON ctr.sid = s.sid

JOIN
Curs c ON c.cid = ctr.cid

JOIN
Sala s ON s.cods = c.sala

WHERE s.etaj = 1;


-- Să se afișeze data nașterii celui mai tânăr și celui mai 
-- bătrân student din anul 2.

SELECT
MIN(s.datan) AS dataOldest,
MAX(s.datan) AS dataYoungest

FROM Student s

WHERE s.an = 2;


-- Să se calculeze suma și media burselor pe fiecare an 
-- de studiu la fiecare facultate. Se vor afișa numele facultății, anul 
-- de studiu, suma și media burselor

SELECT
f.nume,
s.an,
SUM(s.bursa),
AVG(trunc(s.bursa, 2))

FROM Student s

JOIN
Facultate f ON s.fid = f.fid

GROUP BY s.an, f.nume
;


-- Să se afișeze bursa minimă (>0), medie și maximă a 
-- tuturor studenților care au ore in ziua de 'Luni', indiferent de curs.


SELECT 
MIN(distinct bursa) as minBursa,
MAX(distinct bursa) as maxBursa,
trunc(AVG(distinct bursa), 2) as avgBursa

FROM Student s

JOIN 
Contract ctr ON ctr.sid = s.sid

JOIN
Curs c ON c.cid = ctr.cid

WHERE c.zi = 'Luni';


-- Folosind subinterogări și agregări să se afișeze toți 
-- studenții cu bursa peste bursa medie din universitate


SELECT s.sid, s.nume, s.bursa

FROM Student s

WHERE s.bursa > (SELECT AVG(s.bursa) FROM Student s)
;



-- Să se calculeze intervalul de normalitate a mediilor 
-- pentru fiecare facultate în parte. Se va afișa numele fiecărei 
-- facultăți precum și pragurile de jos și de sus a intervalului de 
-- normalitate pentru mediile studenților din acea facultate


SELECT
f.fid, f.nume,
AVG(s.media),
trunc(variance(s.media), 2) as varianta,
trunc(avg(s.media), 2) - trunc(stddev(s.media), 2) as m1,
trunc(avg(s.media), 2) + trunc(stddev(s.media), 2) as m2


FROM
Facultate f

JOIN
Student s on f.fid = s.fid

GROUP BY f.nume, f.fid

;


-- Folosind subinterogări și agregări să se afișeze toți 
-- studenții care au medii în afara intervalului de normalitate a 
-- mediilor pe universitate


SELECT s.sid, s.nume

FROM Student s

WHERE 
s.media < (SELECT trunc(avg(s.media), 2) - trunc(stddev(s.media), 2) FROM Student s)
OR
s.media > (SELECT trunc(avg(s.media), 2) + trunc(stddev(s.media), 2) FROM Student s)

;
SELECT
COUNT(*) AS nrStud,
COUNT(bursa) AS nrBurse,
COUNT(DISTINCT bursa) AS nrNiveluriBurse
FROM Student;


-- Nivelurile minime si maxime ale burselor
SELECT
MIN(bursa) as bursaMin,
MAX(bursa) as bursaMax
FROM Student
WHERE bursa > 0;


-- varianta si interval de normalitate [m1, m2] a mediilor
SELECT 
trunc(variance(media), 2) AS varianta,
trunc(avg(media), 2) - trunc(stddev(media), 2) AS m1,
trunc(avg(media), 2) + trunc(stddev(media), 2) AS m2
FROM Student;


SELECT an AS anStudiu,
COUNT(*) AS nrStudAn
FROM Student
GROUP BY an
HAVING COUNT(*) > 3;

-- Să se calculeze numărul de studenți care nu au bursă 
-- și au media peste 7.50.

SELECT COUNT(*) as nrStud
FROM Student s
WHERE (bursa = 0 OR bursa IS NULL) AND media > 7.50;


-- Să se calculeze numărul de studenți care au ore cu 
-- profesorul 'Luca Caragiale'.

SELECT COUNT(s.sid) AS nrStud
FROM Student s

JOIN
Contract ctr ON ctr.sid = s.sid

JOIN
Curs c ON c.cid = ctr.cid

WHERE c.pid = (SELECT pid from Profesor WHERE nume = 'Luca Caragiale')


-- Să se calculeze numărul total de studenți care au ore 
-- la etajul 1 (încărcarea sălilor de la etajul 1), indiferent de 
-- facultate si de zi

SELECT COUNT(DISTINCT s.sid) AS nrStud
FROM Student s

JOIN
Contract ctr ON ctr.sid = s.sid

JOIN
Curs c ON c.cid = ctr.cid

JOIN
Sala s ON s.cods = c.sala

WHERE s.etaj = 1;

-- Să se afișeze data nașterii celui mai tânăr și celui mai 
-- bătrân student din anul 2.

SELECT
MIN(s.datan) AS dataOldest,
MAX(s.datan) AS dataYoungest

FROM Student s

WHERE s.an = 2;

-- Să se calculeze suma și media burselor pe fiecare an 
-- de studiu la fiecare facultate. Se vor afișa numele facultății, anul 
-- de studiu, suma și media burselor

SELECT
f.nume,
s.an,
SUM(s.bursa),
AVG(trunc(s.bursa, 2))

FROM Student s

JOIN
Facultate f ON s.fid = f.fid

GROUP BY s.an, f.nume
;

-- Să se afișeze bursa minimă (>0), medie și maximă a 
-- tuturor studenților care au ore in ziua de 'Luni', indiferent de curs.


SELECT 
MIN(distinct bursa) as minBursa,
MAX(distinct bursa) as maxBursa,
trunc(AVG(distinct bursa), 2) as avgBursa

FROM Student s

JOIN 
Contract ctr ON ctr.sid = s.sid

JOIN
Curs c ON c.cid = ctr.cid

WHERE c.zi = 'Luni';

-- Folosind subinterogări și agregări să se afișeze toți 
-- studenții cu bursa peste bursa medie din universitate


SELECT s.sid, s.nume, s.bursa

FROM Student s

WHERE s.bursa > (SELECT AVG(s.bursa) FROM Student s)
;

-- Să se calculeze intervalul de normalitate a mediilor 
-- pentru fiecare facultate în parte. Se va afișa numele fiecărei 
-- facultăți precum și pragurile de jos și de sus a intervalului de 
-- normalitate pentru mediile studenților din acea facultate


SELECT
f.fid, f.nume,
AVG(s.media),
trunc(variance(s.media), 2) as varianta,
trunc(avg(s.media), 2) - trunc(stddev(s.media), 2) as m1,
trunc(avg(s.media), 2) + trunc(stddev(s.media), 2) as m2


FROM
Facultate f

JOIN
Student s on f.fid = s.fid

GROUP BY f.nume, f.fid

;


-- Folosind subinterogări și agregări să se afișeze toți 
-- studenții care au medii în afara intervalului de normalitate a 
-- mediilor pe universitate


SELECT s.sid, s.nume

FROM Student s

WHERE 
s.media < (SELECT trunc(avg(s.media), 2) - trunc(stddev(s.media), 2) FROM Student s)
OR
s.media > (SELECT trunc(avg(s.media), 2) + trunc(stddev(s.media), 2) FROM Student s)

;
