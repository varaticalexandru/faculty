-- Să se scrie două interogări SQL, una care listează toți
-- studenții de sex feminin și cealaltă pe cei de sex masculin. Se va 
-- afișa numele, cnp-ul și anul de studiu.

SELECT sid, cnp, nume, datan, adr, an, media, bursa, fid
FROM Student
WHERE substr(cnp, 0, 1)=1 OR substr(cnp, 0, 1)=3 OR substr(cnp, 0, 1)=5 OR substr(cnp, 0, 1)=7;

SELECT sid, cnp, nume, datan, adr, an, media, bursa, fid
FROM Student
WHERE substr(cnp, 0, 1)!=1 AND substr(cnp, 0, 1)!=3 AND substr(cnp, 0, 1)!=5 AND substr(cnp, 0, 1)!=7;