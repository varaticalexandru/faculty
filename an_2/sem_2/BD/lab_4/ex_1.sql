-- Să se listeze toți profesorii împreună cu datele despre 
-- facultatea de care aparțin.


SELECT p.nume as nume_profesor, f.nume as nume_facultate, f.adr as adresa_facultate, f.tel as telefon_facultate
FROM profesor p, facultate f
WHERE p.fid = f.fid;


select
    pid, cnp, p.nume, p.fid, f.nume as numefacultate, f.adr, f.tel
from
    profesor p left join facultate f on p.fid = f.fid