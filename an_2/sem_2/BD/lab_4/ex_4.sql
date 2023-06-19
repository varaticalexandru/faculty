-- Să se listeze toate cursurile care se țin în ziua curenta
-- împreună cu numele profesorilor care le susțin. Denumirea zilei
-- curente fără diacritice se poate afla folosind funcția TO-CHAR

select
    cid, titlu, an, zi, ora, sala, nume
from
    curs c left join profesor p on c.pid = p.pid
where
    c.zi = trim(convert(to_char(SYSDATE, 'Day', 'NLS_DATE_LANGUAGE = Romanian'),'US7ASCII'))