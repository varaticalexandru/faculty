-- nr total de studenti inscrisi la fiecare facultate
SELECT st.fid, count(*) as nrStudenti
FROM Student st
GROUP BY st.fid;

-- bugetul alocat burselor fiecarei facultati (sumarea burselor studentilor de la fiecare facultate)
SELECT st.fid, SUM(st.bursa) as bugetFacultate
FROM Student st
GROUP BY st.fid

-- nr total de studenti inscrisi la fiecare facultate
-- unde nr total de studenti este mai mare decat un parametru P_NSMIN
SELECT fid, nrStudenti
FROM
(
SELECT st.fid, count(*) as nrStudenti
FROM Student st
GROUP BY st.fid
)
WHERE nrStudenti > :P_NSMIN;


-- bugetul alocat burselor fiecarei facultati (sumarea burselor studentilor de la fiecare facultate)
-- unde nr total de studenti este mai mare decat un parametru P_NSMIN
SELECT fid, bugetFacultate
FROM
(
    SELECT st.fid, COUNT(st.fid) as nrStudenti, SUM(st.bursa) as bugetFacultate
    FROM Student st
    GROUP BY st.fid
)
WHERE nrStudenti > :P_NSMIN;
;