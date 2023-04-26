-- Folosind subinterogări și agregări să se afișeze toți 
-- studenții cu bursa peste bursa medie din universitate


SELECT s.sid, s.nume, s.bursa

FROM Student s

WHERE s.bursa > (SELECT AVG(s.bursa) FROM Student s)
;