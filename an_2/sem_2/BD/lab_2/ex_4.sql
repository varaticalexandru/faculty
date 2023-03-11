-- Să se afișeze toți studenții care au împlinit deja sau 
-- vor împlinii anul acesta 20 de ani. Se va afișa numele, anul si 
-- data nașterii. Anul curent se consideră cel obținut cu SYSDATE. 


SELECT nume,
    extract(YEAR FROM DATAN) as an_nastere,
    datan as data_nastere

FROM Student
WHERE abs(extract(YEAR FROM SYSDATE) - extract(YEAR FROM DATAN)) >= 19;