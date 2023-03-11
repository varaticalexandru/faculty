-- Să se listeze toți studenții a căror nume de familie se 
-- termină cu litera ‘u’

SELECT * 
FROM Student
WHERE nume LIKE '%u';