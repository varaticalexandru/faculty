-- Să se listeze toți studenții unde mai există cel puțin 
-- încă un student care are exact aceiași bursă și exact aceiași 
-- medie, indiferent de facultatea la care sunt înscriși.

SELECT s.sid, s.nume, s.bursa, s.media
FROM Student s

WHERE EXISTS

(SELECT sid
FROM Student
WHERE s.sid != sid AND s.bursa = bursa AND s.media = media);
