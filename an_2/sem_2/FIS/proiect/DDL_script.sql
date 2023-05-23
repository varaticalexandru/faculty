-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema fis
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema fis
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `fis` DEFAULT CHARACTER SET utf8 ;
USE `fis` ;

-- -----------------------------------------------------
-- Table `fis`.`furnizor`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `fis`.`furnizor` (
  `ID` VARCHAR(5) NOT NULL,
  `nume` VARCHAR(45) NULL,
  PRIMARY KEY (`ID`),
  UNIQUE INDEX `ID_UNIQUE` (`ID` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `fis`.`comanda`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `fis`.`comanda` (
  `ID` VARCHAR(5) NOT NULL,
  `data` DATE NULL,
  `ID_furnizor` VARCHAR(5) NULL,
  `statut_plata` VARCHAR(45) NULL,
  `statut_livrare` VARCHAR(45) NULL,
  `observatii` VARCHAR(45) NULL,
  PRIMARY KEY (`ID`),
  INDEX `ID_furnizor_fk_idx` (`ID_furnizor` ASC) VISIBLE,
  CONSTRAINT `ID_furnizor_fk`
    FOREIGN KEY (`ID_furnizor`)
    REFERENCES `fis`.`furnizor` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `fis`.`inventar_componente`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `fis`.`inventar_componente` (
  `ID` VARCHAR(5) NOT NULL,
  `nume_componenta` VARCHAR(45) NOT NULL,
  `numar_componente` INT NULL,
  PRIMARY KEY (`ID`, `nume_componenta`),
  CONSTRAINT `ID_comanda_fk`
    FOREIGN KEY (`ID`)
    REFERENCES `fis`.`comanda` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `fis`.`livrare`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `fis`.`livrare` (
  `ID` VARCHAR(5) NOT NULL,
  `data` DATE NULL,
  `statut_plata` VARCHAR(45) NULL,
  `statut_livrare` VARCHAR(45) NULL,
  PRIMARY KEY (`ID`),
  UNIQUE INDEX `ID_UNIQUE` (`ID` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `fis`.`sistem`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `fis`.`sistem` (
  `ID` VARCHAR(5) NOT NULL,
  `familie` VARCHAR(45) NULL,
  `nume` VARCHAR(45) NULL,
  `cantitate_comandata` INT NULL,
  `cantitate_livrata` INT NULL,
  `cantitate_inventar` INT NULL,
  `id_livrare` VARCHAR(5) NULL,
  `pret` FLOAT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE INDEX `ID_sistem_UNIQUE` (`ID` ASC) VISIBLE,
  INDEX `ID_livrare_fk_idx` (`id_livrare` ASC) VISIBLE,
  CONSTRAINT `ID_livrare_fk`
    FOREIGN KEY (`id_livrare`)
    REFERENCES `fis`.`livrare` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `fis`.`component`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `fis`.`component` (
  `ID` VARCHAR(5) NOT NULL,
  `tip` VARCHAR(45) NULL,
  `nume` VARCHAR(45) NULL,
  `ID_sistem` VARCHAR(5) NULL,
  PRIMARY KEY (`ID`),
  UNIQUE INDEX `ID_UNIQUE` (`ID` ASC) VISIBLE,
  INDEX `ID_sistem_fk_idx` (`ID_sistem` ASC) VISIBLE,
  CONSTRAINT `ID_sistem_fk`
    FOREIGN KEY (`ID_sistem`)
    REFERENCES `fis`.`sistem` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `fis`.`garantie`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `fis`.`garantie` (
  `ID` VARCHAR(5) NOT NULL,
  `data` DATE NULL,
  `ID_component` VARCHAR(5) NULL,
  PRIMARY KEY (`ID`),
  UNIQUE INDEX `ID_UNIQUE` (`ID` ASC) VISIBLE,
  INDEX `ID_component_idx` (`ID_component` ASC) VISIBLE,
  CONSTRAINT `ID_component`
    FOREIGN KEY (`ID_component`)
    REFERENCES `fis`.`component` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `fis`.`pachet_promotional`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `fis`.`pachet_promotional` (
  `ID` VARCHAR(5) NOT NULL,
  `nume` VARCHAR(45) NULL,
  PRIMARY KEY (`ID`),
  UNIQUE INDEX `id_pachet_UNIQUE` (`ID` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `fis`.`pachet_include`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `fis`.`pachet_include` (
  `ID_pachet` VARCHAR(5) NOT NULL,
  `ID_sistem` VARCHAR(5) NOT NULL,
  `pret` FLOAT NULL,
  PRIMARY KEY (`ID_pachet`, `ID_sistem`),
  INDEX `ID_sistem_pachet_fk_idx` (`ID_sistem` ASC) VISIBLE,
  CONSTRAINT `ID_pachet_fk`
    FOREIGN KEY (`ID_pachet`)
    REFERENCES `fis`.`pachet_promotional` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `ID_sistem_pachet_fk`
    FOREIGN KEY (`ID_sistem`)
    REFERENCES `fis`.`sistem` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
