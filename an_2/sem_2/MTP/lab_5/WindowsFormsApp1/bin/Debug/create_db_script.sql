-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema Pediatrie
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema Pediatrie
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `Pediatrie` DEFAULT CHARACTER SET utf8 ;
USE `Pediatrie` ;

-- -----------------------------------------------------
-- Table `Pediatrie`.`Pacienti`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Pediatrie`.`Pacienti` (
  `CNP` VARCHAR(13) NOT NULL,
  `Nume` VARCHAR(20) NULL,
  `Prenume` VARCHAR(20) NULL,
  `Sex` VARCHAR(10) NULL,
  `Nume_mama` VARCHAR(50) NULL,
  `Nume_tata` VARCHAR(45) NULL,
  `Data_nasterii` DATETIME NULL,
  `Locul_nasterii` VARCHAR(50) NULL,
  `APGAR` TINYINT(4) NULL,
  `Medic_familie` VARCHAR(50) NULL,
  `Antecedente` LONGTEXT NULL,
  PRIMARY KEY (`CNP`),
  UNIQUE INDEX `CNP_UNIQUE` (`CNP` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Pediatrie`.`Consultatii`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Pediatrie`.`Consultatii` (
  `CNP` VARCHAR(13) NULL,
  `Data` DATETIME NULL,
  `Simptome` VARCHAR(100) NULL,
  `Diagnostic` VARCHAR(100) NULL,
  `Tratament` VARCHAR(255) NULL,
  INDEX `CNP_idx` (`CNP` ASC) VISIBLE,
  CONSTRAINT `CNP_consultatii`
    FOREIGN KEY (`CNP`)
    REFERENCES `Pediatrie`.`Pacienti` (`CNP`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Pediatrie`.`Radiografii`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Pediatrie`.`Radiografii` (
  `CNP` VARCHAR(13) NULL,
  `Data` DATETIME NULL,
  `Nume_imagine` VARCHAR(45) NULL,
  `Diagnostic` VARCHAR(100) NULL,
  `Comentarii` LONGTEXT NULL,
  INDEX `CNP_idx` (`CNP` ASC) VISIBLE,
  CONSTRAINT `CNP_radiografii`
    FOREIGN KEY (`CNP`)
    REFERENCES `Pediatrie`.`Pacienti` (`CNP`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
