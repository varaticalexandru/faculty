-- Să se listeze toți profesorii împreună cu datele despre 
-- facultatea de care aparțin.


SELECT p.nume as nume_profesor, f.nume as nume_facultate, f.adr as adresa_facultate, f.tel as telefon_facultate
FROM profesor p, facultate f
WHERE p.fid = f.fid;



-- Să se listeze toate cursurile de după amiază (>12:00)
-- împreună cu numărul de locuri ale sălii unde se desfășoară

SELECT c.titlu as titlu_curs, c.ora, s.nr_locuri as nr_locuri_sala
FROM Curs c JOIN Sala s
ON c.sala = s.cods
WHERE c.ora > 12;


-- Să se listeze toate cursurile care se țin la etajul 1 (în
-- orice sală de la etajul 1)

SELECT c.titlu as titlu_curs, s.etaj 
FROM curs c, sala s
WHERE s.etaj = 1;


-- Să se listeze toate cursurile care se țin în ziua curenta
-- împreună cu numele profesorilor care le susțin. Denumirea zilei
-- curente fără diacritice se poate afla folosind funcția TO-CHAR

SELECT c.titlu, c.zi
FROM Curs c JOIN Profesor p
ON c.pid = p.pid
WHERE trim(convert(to_char(SYSDATE, 'Day', 'NLS_DATE_LANGUAGE = Romanian'),'US7ASCII')) = c.zi;


-- Să se listeze studenții cu informații despre cursurile 
-- (titlu si sala) la care au nota mai mică sau egală cu 8.


SELECT s.nume, c.titlu, ctr.nota, c.titlu, c.sala
FROM 

Contract ctr JOIN Curs c 
ON ctr.cid = c.cid

FULL JOIN Student s
ON ctr.sid = s.sid

WHERE ctr.nota <= 8;




-- Să se listeze toți studenții care nu au nici un contract 
-- de studii semnat, ordonați după an și nume.

SELECT s.nume, ctr.nrc, s.an, s.nume
FROM

Contract ctr FULL JOIN Student s 
ON ctr.sid = s.sid

WHERE ctr.nrc IS NULL

ORDER BY s.an, s.nume;


-- Să se listeze toți studenții care au cel puțin un 
-- contract de studii semnat, ordonați după numele de familie (obs. 
-- în BD sunt în format “prenume nume_familie”).


SELECT s.nume, ctr.nrc

FROM
Student s LEFT JOIN Contract ctr
ON ctr.sid = s.sid

WHERE ctr.nrc is not null

ORDER BY substr(s.nume, instr(s.nume, ' ')+1);


-- Să se listeze toți studenții care au cursuri în ziua de 
-- ’Luni’

SELECT s.nume as nume_student, c.titlu as titlu_curs, c.zi as zi_curs
FROM 

Contract ctr JOIN Curs c 
ON ctr.cid = c.cid

FULL JOIN Student s
ON ctr.sid = s.sid

WHERE c.zi = 'Luni';


-- Să se listeze toți studenții care au cursuri într-o sală
-- cu mai puțin de 200 de locuri indiferent de zi, ordonați după anul 
-- nașterii și nume


SELECT s.nume as nume_student, c.titlu as titlu_curs, c.sala as sala_curs, sl.nr_locuri
FROM 

Contract ctr FULL JOIN Curs c 
ON ctr.cid = c.cid

JOIN Student s
ON ctr.sid = s.sid

FULL JOIN Sala sl
ON c.cid = sl.cods

WHERE sl.nr_locuri < 200;