-- -----------------------------------------------------
-- Table cbGrad
-- -----------------------------------------------------
CREATE TABLE cbGrad (
    codGrad CHAR(1) NOT NULL,
    denumire VARCHAR2(45),
    tarif NUMBER(8),
    CONSTRAINT cbGrad_pk PRIMARY KEY (codGrad)
    -- CONSTRAINT cbGrad_uk UNIQUE (codGrad)
);

-- -----------------------------------------------------
-- Table cdSpecialitate
-- -----------------------------------------------------
CREATE TABLE cdSpecialitate (
    codSpec VARCHAR2(20) NOT NULL,
    denumire VARCHAR2(45),
    coefPlata NUMBER(4,2),
    CONSTRAINT cdSpecialitate_pk PRIMARY KEY (codSpec)
    -- CONSTRAINT cdSpecialitate_uk UNIQUE (codSpec)
);

-- -----------------------------------------------------
-- Table cbMedic
-- -----------------------------------------------------
CREATE TABLE cbMedic (
    medID CHAR(4) NOT NULL,
    nume VARCHAR2(45),
    codSpec VARCHAR2(20),
    codGrad CHAR(1),
    CONSTRAINT cbMedic_pk PRIMARY KEY (medID),
    CONSTRAINT cbMedic_fk_codSpec FOREIGN KEY (codSpec) REFERENCES cdSpecialitate (codSpec),
    CONSTRAINT cbMedic_fk_codGrad FOREIGN KEY (codGrad) REFERENCES cbGrad (codGrad)
);

-- -----------------------------------------------------
-- Table cbReteta
-- -----------------------------------------------------
CREATE TABLE cbReteta (
    cnp CHAR(13) NOT NULL,
    medicament VARCHAR2(45),
    doza_zi VARCHAR2(5),
    durata_zile NUMBER,
    CONSTRAINT cbReteta_pk PRIMARY KEY (cnp)
    -- CONSTRAINT cbReteta_uk UNIQUE (cnp)
);

-- -----------------------------------------------------
-- Table cbProgramare
-- -----------------------------------------------------
CREATE TABLE cbProgramare (
  codPro CHAR(5) NOT NULL,
  data DATE,
  cnp CHAR(13),
  nume VARCHAR2(45),
  medID CHAR(4),
  cabinet CHAR(4),
  CONSTRAINT cbProgramare_pk PRIMARY KEY (codPro),
  CONSTRAINT cbProgramare_fk_cnp FOREIGN KEY (cnp) REFERENCES cbReteta (cnp),
  CONSTRAINT cbProgramare_fk_medID FOREIGN KEY (medID) REFERENCES cbMedic (medID)
);
