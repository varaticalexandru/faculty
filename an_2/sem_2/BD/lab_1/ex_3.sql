-- Folosind comanda UPDATE cu WHERE să se 
-- modifice numărul de locuri din sala A109 la 82

update sala
set nr_locuri = 82
where cods like 'A109';