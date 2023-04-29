-- -----------------------------------------------------
-- Table cbGrad
-- -----------------------------------------------------
DELETE FROM cbGrad;
INSERT INTO cbGrad (codGrad, denumire, tarif) VALUES ('R', 'rezident', 1500);
INSERT INTO cbGrad (codGrad, denumire, tarif) VALUES ('S', 'specialist', 3000);
INSERT INTO cbGrad (codGrad, denumire, tarif) VALUES ('P', 'primar', 6000);


-- -----------------------------------------------------
-- Table cdSpecialitate
-- -----------------------------------------------------
DELETE FROM cdSpecialitate;
INSERT INTO cdSpecialitate (codSpec, denumire, coefPlata) VALUES ('gastro', 'gastroenterologie', 1.4);
INSERT INTO cdSpecialitate (codSpec, denumire, coefPlata) VALUES ('derm', 'dermatologie', 1.2);
INSERT INTO cdSpecialitate (codSpec, denumire, coefPlata) VALUES ('neuro', 'neurologie', 1.3);
INSERT INTO cdSpecialitate (codSpec, denumire, coefPlata) VALUES ('cardio', 'cardiologie', 1.5);


-- -----------------------------------------------------
-- Table cbMedic
-- -----------------------------------------------------
DELETE FROM cbMedic;
INSERT INTO cbMedic (medID, nume, codSpec, codGrad) VALUES ('M001', 'Popescu Ion', 'gastro', 'R');
INSERT INTO cbMedic (medID, nume, codSpec, codGrad) VALUES ('M002', 'Ionescu Maria', 'derm', 'S');
INSERT INTO cbMedic (medID, nume, codSpec, codGrad) VALUES ('M003', 'Dumitru Andrei', 'neuro', 'P');
INSERT INTO cbMedic (medID, nume, codSpec, codGrad) VALUES ('M004', 'Grigore Alina', 'gastro', 'S');
INSERT INTO cbMedic (medID, nume, codSpec, codGrad) VALUES ('M005', 'Stanescu Mihaela', 'cardio', 'R');
INSERT INTO cbMedic (medID, nume, codSpec, codGrad) VALUES ('M006', 'Cristea Alexandru', 'derm', 'P');
INSERT INTO cbMedic (medID, nume, codSpec, codGrad) VALUES ('M007', 'Mihai Elena', 'neuro', 'S');
INSERT INTO cbMedic (medID, nume, codSpec, codGrad) VALUES ('M008', 'Popa Alexandru', 'cardio', 'P');


-- -----------------------------------------------------
-- Table cbReteta
-- -----------------------------------------------------
DELETE FROM cbReteta;
INSERT INTO cbReteta VALUES ('6121122312421','Fervex','1+1',14);
INSERT INTO cbReteta VALUES ('7170907224191','Paracetamol','1+0+1',10);
INSERT INTO cbReteta VALUES ('3030305354643','Ibuprofen','1+1',7);
INSERT INTO cbReteta VALUES ('3280721107086','Nurofen','1+1',14);
INSERT INTO cbReteta VALUES ('1960222474068','Aspirina','1+0+1',10);
INSERT INTO cbReteta VALUES ('7190205255383','Diazepam','1+0+1',14);
INSERT INTO cbReteta VALUES ('9080624180551','Alprazolam','1+0+1',10);
INSERT INTO cbReteta VALUES ('4030605171638','Clonazepam','1+0+1',7);
INSERT INTO cbReteta VALUES ('1050513396400','Dexametazona','1+0+1',7);
INSERT INTO cbReteta VALUES ('8000422409651','Prednison','1+0+1',14);
INSERT INTO cbReteta VALUES ('5170611322654','Azitromicina','1+0+1',10);
INSERT INTO cbReteta VALUES ('9220303070292','Amoxicilina','1+0+1',14);
INSERT INTO cbReteta VALUES ('1930414196401','Cefalexina','1+0+1',7);
INSERT INTO cbReteta VALUES ('9001202512223','Metronidazol','1+0+1',10);
INSERT INTO cbReteta VALUES ('6130520032920','Fluconazol','1+0+1',14);
INSERT INTO cbReteta VALUES ('9200613521207','Lansoprazol','1+0+1',7);
INSERT INTO cbReteta VALUES ('6130305483893','Omeprazol','1+0+1',10);
INSERT INTO cbReteta VALUES ('2550731416948','Ranitidina','1+0+1',14);
INSERT INTO cbReteta VALUES ('4291025063877','Furosemid','1+1',7);
INSERT INTO cbReteta VALUES ('7150920345030','Digoxin','1+0+1',10);
INSERT INTO cbReteta VALUES ('4260303400197','Ramipril','1+0+1',14);
INSERT INTO cbReteta VALUES ('2160404344621','Enalapril','1+0+1',7);
INSERT INTO cbReteta VALUES ('1720401028616','Amlodipina','1+0+1',10);
INSERT INTO cbReteta VALUES ('3880415301036','Losartan','1+0+1',14);
INSERT INTO cbReteta VALUES ('8091117271042','Hydrochlorothiazide','1+0+1',7);
INSERT INTO cbReteta VALUES ('6120408099184','Aciclovir','1+0+1',10);
INSERT INTO cbReteta VALUES ('6041104175506','Paracetamol','2+2',7);
INSERT INTO cbReteta VALUES ('1610724254973','Nurofen Plus','1+1',10);
INSERT INTO cbReteta VALUES ('5101127312240','Ventolin','1+0+1',14);
INSERT INTO cbReteta VALUES ('9070731241797','Omez','1+0+1',28);
INSERT INTO cbReteta VALUES ('1710531075379','Augmentin','1+1',7);
INSERT INTO cbReteta VALUES ('5020827359255','Gliclazida','1+0+1',30);
INSERT INTO cbReteta VALUES ('7220624017030','Enalapril','1+0+1',60);
INSERT INTO cbReteta VALUES ('6140924336431','Simvastatin','1+0+1',90);
INSERT INTO cbReteta VALUES ('5160329091244','Amlodipina','1+0+1',30);
INSERT INTO cbReteta VALUES ('5030313463727','Bisoprolol','1+0+1',90);
INSERT INTO cbReteta VALUES ('6070215496237','Aspirina Protect','1+0+1',30);
INSERT INTO cbReteta VALUES ('8060324454738','Metformin','1+0+1',60);
INSERT INTO cbReteta VALUES ('2280523324128','Atorvastatin','1+0+1',30);
INSERT INTO cbReteta VALUES ('3161215245858','Diazepam','1+1',7);


-- -----------------------------------------------------
-- Table cbProgramare
-- -----------------------------------------------------
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7278', '04.24.2023', '6121122312421', 'Popa Andrei', 'M004', 'C104');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7279', '04.25.2023', '7170907224191', 'Georgescu Maria', 'M003', 'C102');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7280', '04.26.2023', '3030305354643', 'Ionescu Andrei', 'M006', 'C101');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7281', '04.27.2023', '7220624017030', 'Dumitru Ana', 'M001', 'C103');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7282', '04.28.2023', '7150920345030', 'Radulescu Ion', 'M002', 'C101');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7283', '04.29.2023', '6041104175506', 'Nicolescu Maria', 'M005', 'C102');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7284', '04.30.2023', '9200613521207', 'Munteanu Stefan', 'M001', 'C104');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7285', '05.01.2023', '5020827359255', 'Popescu Elena', 'M003', 'C103');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7286', '05.02.2023', '3161215245858', 'Ungureanu Alexandru', 'M006', 'C102');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7287', '05.03.2023', '2280523324128', 'Dumitrache Alina', 'M005', 'C101');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7288', '05.04.2023', '8060324454738', 'Tudor Ion', 'M002', 'C104');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7289', '05.05.2023', '6070215496237', 'Popa Maria', 'M004', 'C103');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7290', '06.05.2023', '5030313463727', 'Neacsu Stefan', 'M001', 'C101');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7291', '07.05.2023', '5160329091244', 'Radu Ioana', 'M003', 'C104');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7292', '08.05.2023', '6140924336431', 'Stanescu Marian', 'M005', 'C102');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7293', '09.05.2023', '1710531075379', 'Iacobescu Andreea', 'M002', 'C101');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7294', '10.05.2023', '9070731241797', 'Petrescu Ana', 'M006', 'C103');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7295', '11.05.2023', '6120408099184', 'Ionescu Maria', 'M004', 'C104');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7296', '12.05.2023', '8091117271042', 'Stefanescu Alexandru', 'M001', 'C102');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7297', '05.13.2023', '1720401028616', 'Popescu Dan', 'M003', 'C101');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7298', '05.15.2023', '2160404344621', 'Vasilescu Ioana', 'M006', 'C103');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7299', '05.16.2023', '4291025063877', 'Popescu Andrei', 'M001', 'C101');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7300', '05.17.2023', '6130520032920', 'Dumitrescu Maria', 'M005', 'C104');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7301', '05.18.2023', '8000422409651', 'Radulescu Ionut', 'M002', 'C103');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7302', '05.19.2023', '1930414196401', 'Nicolescu Stefan', 'M004', 'C102');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7303', '05.20.2023', '5101127312240','Munteanu Alexandru','M003','C101');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7304', '05.21.2023', '9001202512223','Ungureanu Maria','M006','C104');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7305', '05.22.2023', '8000422409651','Iacobescu Stefan','M002','C102');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7306', '05.23.2023', '1710531075379','Vasile Ionut','M004','C103');
INSERT INTO cbProgramare (codPro, data, cnp, nume, medID, cabinet) VALUES ('7307', '05.24.2023', '5020827359255','Popescu Alina','M005','C101');