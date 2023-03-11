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