-- Să se listeze toți profesorii împreună cu datele despre 
-- facultatea de care aparțin.


SELECT p.nume as nume_profesor, f.nume as nume_facultate, f.adr as adresa_facultate, f.tel as telefon_facultate
FROM profesor p, facultate f
WHERE p.fid = f.fid;