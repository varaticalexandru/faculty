
-- cate componente (specifica id_componenta) am primit in total in 2022 (din comenzi)
select sum(numar_componente)
from inventar_componente i
join comanda c on i.ID = c.ID
where c.data like '2022-__-__' AND i.id_componenta = 'c1'
;

-- cate componente (specifica id_componenta) am folosit in total in 2022 (in sisteme)
select count(*)
from sistem s
join sistem_component sc on s.ID = sc.ID_sistem
where s.data_creare like '2022-__-__' AND sc.id_component = 'c1'
;