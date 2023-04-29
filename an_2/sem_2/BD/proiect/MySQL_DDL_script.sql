-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8mb3 ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`cbGrad`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`cbGrad` (
  `codGrad` CHAR(1) NOT NULL,
  `denumire` VARCHAR(45) NULL,
  `tarif` FLOAT NULL,
  PRIMARY KEY (`codGrad`),
  UNIQUE INDEX `codGrad_UNIQUE` (`codGrad` ASC) VISIBLE)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb3;


-- -----------------------------------------------------
-- Table `mydb`.`cdSpecialitate`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`cdSpecialitate` (
  `codSpec` VARCHAR(20) NOT NULL,
  `denumire` VARCHAR(45) NULL,
  `coefPlata` FLOAT NULL,
  PRIMARY KEY (`codSpec`),
  UNIQUE INDEX `codSpec_UNIQUE` (`codSpec` ASC) VISIBLE)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb3;


-- -----------------------------------------------------
-- Table `mydb`.`cbMedic`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`cbMedic` (
  `medID` CHAR(4) NOT NULL,
  `nume` VARCHAR(45) NULL,
  `codSpec` VARCHAR(20) NULL,
  `codGrad` CHAR(1) NULL,
  PRIMARY KEY (`medID`),
  INDEX `codSpec_idx` (`codSpec` ASC) VISIBLE,
  INDEX `codGrad_idx` (`codGrad` ASC) VISIBLE,
  UNIQUE INDEX `medID_UNIQUE` (`medID` ASC) VISIBLE,
  CONSTRAINT `codGrad`
    FOREIGN KEY (`codGrad`)
    REFERENCES `mydb`.`cbGrad` (`codGrad`),
  CONSTRAINT `codSpec`
    FOREIGN KEY (`codSpec`)
    REFERENCES `mydb`.`cdSpecialitate` (`codSpec`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb3;


-- -----------------------------------------------------
-- Table `mydb`.`cbReteta`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`cbReteta` (
  `cnp` CHAR(13) NOT NULL,
  `medicament` VARCHAR(45) NULL,
  `doza_zi` VARCHAR(5) NULL,
  `durata_zile` INT NULL,
  PRIMARY KEY (`cnp`),
  UNIQUE INDEX `cnp_UNIQUE` (`cnp` ASC) VISIBLE)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb3;


-- -----------------------------------------------------
-- Table `mydb`.`cbProgramare`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`cbProgramare` (
  `codPro` CHAR(5) NOT NULL,
  `data` DATE NULL,
  `cnp` CHAR(13) NULL,
  `nume` VARCHAR(45) NULL,
  `medID` CHAR(4) NULL,
  `cabinet` CHAR(4) NULL,
  PRIMARY KEY (`codPro`),
  INDEX `medID_idx` (`medID` ASC) VISIBLE,
  INDEX `cnp_idx` (`cnp` ASC) VISIBLE,
  UNIQUE INDEX `codPro_UNIQUE` (`codPro` ASC) VISIBLE,
  CONSTRAINT `cnp`
    FOREIGN KEY (`cnp`)
    REFERENCES `mydb`.`cbReteta` (`cnp`),
  CONSTRAINT `medID`
    FOREIGN KEY (`medID`)
    REFERENCES `mydb`.`cbMedic` (`medID`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb3;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
