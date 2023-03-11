
--ex 1
-- Să se listeze toți studenții a căror nume de familie se 
-- termină cu litera ‘u’

SELECT * 
FROM Student
WHERE nume LIKE '%u';




--ex 2
-- Considerând că toți studenții au un singur prenume, 
-- să se afișeze o lista cu numele de familie, prenumele și anul de 
-- studiu a tuturor studenților.

SELECT an, nume,
    CASE WHEN 1 = 1 THEN '-'
    END
    AS prenume
FROM Student;



--ex 3
-- Să se listeze toți studenții a căror prenume este mai 
-- lung de 7 caractere inclusiv. Se va afișa numele complet, 
-- prenumele și lungimea prenumelui pentru verificare.


SELECT nume as nume_complet, 
    SUBSTR(nume, 0, INSTR(nume, ' ')) as prenume,
    SUBSTR(nume, INSTR(nume, ' ')) as nume,
    length(SUBSTR(nume, 0, INSTR(nume, ' '))) as lungime_prenume

FROM Student
WHERE length(SUBSTR(nume, 0, INSTR(nume, ' '))) >= 7;




--ex 4
-- Să se afișeze toți studenții care au împlinit deja sau 
-- vor împlinii anul acesta 20 de ani. Se va afișa numele, anul si 
-- data nașterii. Anul curent se consideră cel obținut cu SYSDATE. 


SELECT nume,
    extract(YEAR FROM DATAN) as an_nastere,
    datan as data_nastere

FROM Student
WHERE abs(extract(YEAR FROM SYSDATE) - extract(YEAR FROM DATAN)) >= 19;




--ex 5
-- Să se afișeze toți studenții care își serbează ziua de 
-- naștere în luna curentă. 
-- Obs: luna curentă se va obține din 
-- SYSDATE.


SELECT *
FROM Student
WHERE extract(MONTH FROM SYSDATE) = extract(MONTH FROM datan);




--ex 6
-- Să se afișeze toți studenții care nu au completat 
-- câmpul bursa (a căror bursă nu se cunoaște). Cu o nouă 
-- interogare afișați apoi studenții care nu au bursă.


SELECT * 
FROM Student
WHERE bursa iS NULL;

SELECT *
FROM Student
WHERE bursa = 0;




--ex 7
-- Să se afișeze toți studenții din anul 2. Se va afișa 
-- numele, anul si CNP-ul. Pentru studenții care nu au completat 
-- CNP-ul se va afișa ‘CNP necompletat’.

SELECT nume, an,
    CASE WHEN cnp IS NULL THEN 'CNP necompletat'
    ELSE CNP
    END
    as CNP

FROM student
WHERE an = 2;


--ex 8
-- Să se scrie două interogări SQL, una care listează toți
-- studenții de sex feminin și cealaltă pe cei de sex masculin. Se va 
-- afișa numele, cnp-ul și anul de studiu.

SELECT sid, cnp, nume, datan, adr, an, media, bursa, fid
FROM Student
WHERE substr(cnp, 0, 1)=1 OR substr(cnp, 0, 1)=3 OR substr(cnp, 0, 1)=5 OR substr(cnp, 0, 1)=7;

SELECT sid, cnp, nume, datan, adr, an, media, bursa, fid
FROM Student
WHERE substr(cnp, 0, 1)!=1 AND substr(cnp, 0, 1)!=3 AND substr(cnp, 0, 1)!=5 AND substr(cnp, 0, 1)!=7;




--ex 9
-- Se consideră studenții împărțiți în două grupuri – fete 
-- și respectiv băieți. Să se afișeze toți studenți afișând numele, anul 
-- de studiu și grupul (fete sau băieți) din care fac parte

SELECT sid, cnp, nume, datan, adr, an, media, bursa, fid,
    CASE WHEN substr(cnp, 0, 1)=1 OR substr(cnp, 0, 1)=3 OR substr(cnp, 0, 1)=5 OR substr(cnp, 0, 1)=7
    THEN 'baieti'
    ELSE 'fete'
    END
    as grup

FROM Student;