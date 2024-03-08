BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE tranzactie';
EXCEPTION
    WHEN OTHERS THEN NULL;
END;
/

BEGIN
    EXECUTE IMMEDIATE 'DROP TABLE cont';
EXCEPTION
    WHEN OTHERS THEN NULL;
END;
/

BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE nrCont_Seq';
EXCEPTION
    WHEN OTHERS THEN NULL;
END;
/

BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE nrTranzactie_Seq';
EXCEPTION
    WHEN OTHERS THEN NULL;
END;
/

-- -----------------------------------------------------
-- Table cont
-- -----------------------------------------------------
CREATE SEQUENCE nrCont_Seq
  START WITH 0
  INCREMENT BY 1
  MINVALUE 0
  MAXVALUE 99999
  NOCYCLE
  NOCACHE;
 
CREATE TABLE cont (
    nrCont VARCHAR2(20),
    descriere VARCHAR2(50),
    tipCont VARCHAR2(2),
    soldInitial NUMBER,
    soldCurent NUMBER
);

ALTER TABLE cont
    ADD (
        CONSTRAINT PK_cont PRIMARY KEY (nrCont),
        CONSTRAINT CHK_tipCont CHECK (tipCont in ('ca', 'pa', 'ac' )),
        CONSTRAINT CHK_nrContLength CHECK (LENGTH(nrCont) = 5)
    );

ALTER TABLE cont
    MODIFY (
        nrCont DEFAULT LPAD(TO_CHAR(nrCont_Seq.NEXTVAL), 5, '0')
    );


-- -----------------------------------------------------
-- Table tranzactie
-- -----------------------------------------------------
CREATE SEQUENCE nrTranzactie_Seq
  START WITH 0
  INCREMENT BY 1
  MINVALUE 0
  MAXVALUE 10000
  NOCYCLE
  NOCACHE;

CREATE TABLE tranzactie (
    nrTranzactie NUMBER(5),
    dataTranzactie DATE,
    contSursa VARCHAR2(5),
    contDest VARCHAR2(5),
    suma NUMBER,
    descriere VARCHAR2(10)
);

ALTER TABLE tranzactie
    ADD (
        CONSTRAINT CHK_nrTranzactie CHECK (nrTranzactie <= 10000),
        CONSTRAINT CHK_suma CHECK (suma <= 10000),
        CONSTRAINT FK_contSursa FOREIGN KEY (contSursa) REFERENCES cont(nrCont),
        CONSTRAINT FK_contDest FOREIGN KEY (contDest) REFERENCES cont(nrCont)
    );

CREATE OR REPLACE TRIGGER check_dataTranzactie 
    BEFORE INSERT OR UPDATE ON tranzactie
    FOR EACH ROW
BEGIN
    IF (EXTRACT(YEAR FROM :NEW.dataTranzactie) != EXTRACT(YEAR FROM SYSDATE)) THEN 
        RAISE_APPLICATION_ERROR(-20001, 'Anul tranzactiei trebuie sa corespunda anului curent.');
    END IF;
END;
/

ALTER TABLE tranzactie
    MODIFY (
        nrTranzactie DEFAULT nrTranzactie_Seq.NEXTVAL
    );

CREATE OR REPLACE TRIGGER upd_Solduri
    AFTER INSERT ON tranzactie
    FOR EACH ROW
BEGIN
    -- actualizare cont debitor (sursa)
    UPDATE cont
    SET soldCurent = soldCurent - :NEW.suma
    WHERE nrCont = :NEW.contSursa;

    -- actualizare cont creditor (dest)
    UPDATE cont
    SET soldCurent = soldCurent + :NEW.suma
    WHERE nrCont = :NEW.contDest;
END;
/