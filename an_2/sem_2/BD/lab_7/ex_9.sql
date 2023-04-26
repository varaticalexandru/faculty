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
