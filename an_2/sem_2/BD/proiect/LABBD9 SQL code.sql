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
CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`cdSpecialitate`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`cdSpecialitate` (
  `codSpec` VARCHAR(20) NOT NULL,
  `denumire` VARCHAR(45) NOT NULL,
  `coefPlata` FLOAT NOT NULL,
  PRIMARY KEY (`codSpec`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`cbGrad`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`cbGrad` (
  `codGrad` CHAR(1) NOT NULL,
  `denumire` VARCHAR(45) NOT NULL,
  `tarif` FLOAT NOT NULL,
  PRIMARY KEY (`codGrad`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`cbMedic`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`cbMedic` (
  `medID` CHAR(4) NOT NULL,
  `nume` VARCHAR(45) NOT NULL,
  `codSpec` VARCHAR(20) NOT NULL,
  `codGrad` CHAR(1) NOT NULL,
  PRIMARY KEY (`medID`),
  INDEX `codSpec_idx` (`codSpec` ASC) VISIBLE,
  INDEX `codGrad_idx` (`codGrad` ASC) VISIBLE,
  CONSTRAINT `codSpec`
    FOREIGN KEY (`codSpec`)
    REFERENCES `mydb`.`cdSpecialitate` (`codSpec`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `codGrad`
    FOREIGN KEY (`codGrad`)
    REFERENCES `mydb`.`cbGrad` (`codGrad`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`cbReteta`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`cbReteta` (
  `cnp` CHAR(13) NOT NULL,
  `medicament` VARCHAR(45) NOT NULL,
  `doza_zi` VARCHAR(5) NOT NULL,
  `durata_zile` INT(3) NOT NULL,
  PRIMARY KEY (`cnp`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`cbProgramare`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`cbProgramare` (
  `codPro` CHAR(5) NOT NULL,
  `data` DATE NOT NULL,
  `cnp` CHAR(13) NOT NULL,
  `nume` VARCHAR(45) NOT NULL,
  `medID` CHAR(4) NOT NULL,
  `cabinet` CHAR(4) NOT NULL,
  PRIMARY KEY (`codPro`),
  INDEX `medID_idx` (`medID` ASC) VISIBLE,
  INDEX `cnp_idx` (`cnp` ASC) VISIBLE,
  CONSTRAINT `medID`
    FOREIGN KEY (`medID`)
    REFERENCES `mydb`.`cbMedic` (`medID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `cnp`
    FOREIGN KEY (`cnp`)
    REFERENCES `mydb`.`cbReteta` (`cnp`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
