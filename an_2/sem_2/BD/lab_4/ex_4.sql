-- Să se listeze toate cursurile care se țin în ziua curenta
-- împreună cu numele profesorilor care le susțin. Denumirea zilei
-- curente fără diacritice se poate afla folosind funcția TO-CHAR

SELECT c.titlu, c.zi
FROM Curs c JOIN Profesor p
ON c.pid = p.pid
WHERE trim(convert(to_char(SYSDATE, 'Day', 'NLS_DATE_LANGUAGE = Romanian'),'US7ASCII')) = c.zi;