-- Oracle APEX 22.2.2 SQL
-- Schema: BD_Universitate
-- DAN.PESCARU@CS.UPT.RO


CREATE TABLE Facultate(
fid CHAR (3) NOT NULL, 
nume VARCHAR2 (32), 
adr VARCHAR2 (32), 
tel VARCHAR2 (12),
CONSTRAINT facult_pk PRIMARY KEY(fid)
);

CREATE TABLE Student(
sid CHAR(6) NOT NULL, 
cnp CHAR (13), 
nume VARCHAR2(32) NOT NULL, 
datan DATE, 
adr VARCHAR2 (32),
an NUMBER(1) NOT NULL, 
media NUMBER (4,2), 
bursa NUMBER (5,0),
fid CHAR (3) NOT NULL ,
CONSTRAINT stud_pk PRIMARY KEY(sid),
CONSTRAINT facult_fk  FOREIGN KEY (fid) REFERENCES Facultate(fid)
);


CREATE TABLE Profesor(
pid CHAR (6) NOT NULL, 
cnp CHAR (13), 
nume VARCHAR2 (32), 
datan DATE, 
fid CHAR (3) NOT NULL,
CONSTRAINT prof_pk PRIMARY KEY(pid),
CONSTRAINT pfacult_fk  FOREIGN KEY (fid) REFERENCES Facultate(fid)
);

CREATE TABLE Sala(
cods CHAR (4) NOT NULL, 
etaj NUMBER (2), 
nr_locuri NUMBER (3),
CONSTRAINT sala_pk PRIMARY KEY(cods)
);

CREATE TABLE Curs(
cid CHAR (5) NOT NULL, 
titlu VARCHAR2 (32) NOT NULL, 
fid CHAR (3) NOT NULL,
an NUMBER (1) NOT NULL, 
pid CHAR (6), 
zi VARCHAR2 (8), 
ora NUMBER (2), 
sala CHAR (4),
CONSTRAINT crs_pk PRIMARY KEY(cid),
CONSTRAINT cfacult_fk  FOREIGN KEY (fid) REFERENCES Facultate(fid),
CONSTRAINT crssala_fk  FOREIGN KEY (sala) REFERENCES Sala(cods)
);

CREATE TABLE Contract(
nrc NUMBER (5) NOT NULL, 
sid CHAR (6) NOT NULL, 
cid CHAR(5) NOT NULL, 
an NUMBER (4) NOT NULL, 
semestru NUMBER (1), 
nota NUMBER (4,2),
CONSTRAINT contr_pk PRIMARY KEY(nrc),
CONSTRAINT constd_fk  FOREIGN KEY (sid) REFERENCES Student(sid),
CONSTRAINT concrs_fk  FOREIGN KEY (cid) REFERENCES Curs(cid)
);