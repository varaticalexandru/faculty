-- Să se afișeze toți studenții care își serbează ziua de 
-- naștere în luna curentă. 
-- Obs: luna curentă se va obține din 
-- SYSDATE.


SELECT *
FROM Student
WHERE extract(MONTH FROM SYSDATE) = extract(MONTH FROM datan);