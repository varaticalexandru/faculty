-- Folosind ALTER TABLE să se adauge o constrângere
-- la tabela student care să verifice că anul de studiu este între 1 si 4

alter table student
modify an number(1,0)
check (an <= 4 and an  >= 1);