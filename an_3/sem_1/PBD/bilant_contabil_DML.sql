-- -----------------------------------------------------
-- Table cont
-- -----------------------------------------------------
DELETE FROM tranzactie;
DELETE FROM cont;

INSERT INTO cont (descriere, tipCont, soldInitial, soldCurent)
VALUES ('Cont capital SRL 123', 'ca', 4000, 800);

INSERT INTO cont (descriere, tipCont, soldInitial, soldCurent)
VALUES ('Cont pasiv SA 666', 'pa', 2000, 1800);

INSERT INTO cont (descriere, tipCont, soldInitial, soldCurent)
VALUES ('Cont activ SC 777', 'ac', 3000, 2500);

INSERT INTO cont (descriere, tipCont, soldInitial, soldCurent)
VALUES ('Cont capital SRL X7', 'ca', 1500, 1200);

INSERT INTO cont (descriere, tipCont, soldInitial, soldCurent)
VALUES ('Cont pasiv SC 777', 'pa', 2200, 2000);

INSERT INTO cont (descriere, tipCont, soldInitial, soldCurent)
VALUES ('Descriere activ SA ZZ', 'ac', 3500, 3100);

INSERT INTO cont (descriere, tipCont, soldInitial, soldCurent)
VALUES ('Descriere capital SC IEEE', 'ca', 1800, 1500);



-- -----------------------------------------------------
-- Table tranzactie
-- -----------------------------------------------------

INSERT INTO tranzactie (dataTranzactie, contSursa, contDest, suma, descriere)
VALUES ('01.01.2023', '00000', '00001', 100, '0->1: 100');

INSERT INTO tranzactie (dataTranzactie, contSursa, contDest, suma, descriere)
VALUES ('03.20.2023', '00001', '00002', 50, '1->2: 50');

INSERT INTO tranzactie (dataTranzactie, contSursa, contDest, suma, descriere)
VALUES ('05.31.2023', '00002', '00003', 200, '2->3: 1200');

INSERT INTO tranzactie (dataTranzactie, contSursa, contDest, suma, descriere)
VALUES ('11.12.2023', '00003', '00004', 70, '3->4: 70');

INSERT INTO tranzactie (dataTranzactie, contSursa, contDest, suma, descriere)
VALUES ('12.01.2023', '00004', '00005', 25, '4->5: 25');

INSERT INTO tranzactie (dataTranzactie, contSursa, contDest, suma, descriere)
VALUES ('08.01.2023', '00005', '00006', 250, '5->6: 250');