-- MySQL dump 10.13  Distrib 8.0.32, for Win64 (x86_64)
--
-- Host: localhost    Database: fis
-- ------------------------------------------------------
-- Server version	8.0.32

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `comanda`
--

DROP TABLE IF EXISTS `comanda`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `comanda` (
  `ID` varchar(5) NOT NULL,
  `data` date DEFAULT NULL,
  `ID_furnizor` varchar(5) DEFAULT NULL,
  `statut_plata` varchar(45) DEFAULT NULL,
  `statut_livrare` varchar(45) DEFAULT NULL,
  `observatii` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `ID_furnizor_fk_idx` (`ID_furnizor`),
  CONSTRAINT `ID_furnizor_fk` FOREIGN KEY (`ID_furnizor`) REFERENCES `furnizor` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `component`
--

DROP TABLE IF EXISTS `component`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `component` (
  `ID` varchar(5) NOT NULL,
  `tip` varchar(26) DEFAULT NULL,
  `nume` varchar(90) DEFAULT NULL,
  `ID_sistem` varchar(5) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `ID_UNIQUE` (`ID`),
  KEY `ID_sistem_fk_idx` (`ID_sistem`),
  CONSTRAINT `ID_sistem_fk` FOREIGN KEY (`ID_sistem`) REFERENCES `sistem` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `furnizor`
--

DROP TABLE IF EXISTS `furnizor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `furnizor` (
  `ID` varchar(5) NOT NULL,
  `nume` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `ID_UNIQUE` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `garantie`
--

DROP TABLE IF EXISTS `garantie`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `garantie` (
  `ID` varchar(5) NOT NULL,
  `data` date DEFAULT NULL,
  `ID_component` varchar(5) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `ID_UNIQUE` (`ID`),
  KEY `ID_component_idx` (`ID_component`),
  CONSTRAINT `ID_component` FOREIGN KEY (`ID_component`) REFERENCES `component` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `inventar_componente`
--

DROP TABLE IF EXISTS `inventar_componente`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `inventar_componente` (
  `ID` varchar(5) NOT NULL,
  `nume_componenta` varchar(90) NOT NULL,
  `numar_componente` int DEFAULT NULL,
  PRIMARY KEY (`ID`,`nume_componenta`),
  CONSTRAINT `ID_comanda_fk` FOREIGN KEY (`ID`) REFERENCES `comanda` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `livrare`
--

DROP TABLE IF EXISTS `livrare`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `livrare` (
  `ID` varchar(5) NOT NULL,
  `data` date DEFAULT NULL,
  `statut_plata` varchar(45) DEFAULT NULL,
  `statut_livrare` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `ID_UNIQUE` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `pachet_include`
--

DROP TABLE IF EXISTS `pachet_include`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pachet_include` (
  `ID_pachet` varchar(5) NOT NULL,
  `ID_sistem` varchar(5) NOT NULL,
  `pret` float DEFAULT NULL,
  PRIMARY KEY (`ID_pachet`,`ID_sistem`),
  KEY `ID_sistem_pachet_fk_idx` (`ID_sistem`),
  CONSTRAINT `ID_pachet_fk` FOREIGN KEY (`ID_pachet`) REFERENCES `pachet_promotional` (`ID`),
  CONSTRAINT `ID_sistem_pachet_fk` FOREIGN KEY (`ID_sistem`) REFERENCES `sistem` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `pachet_promotional`
--

DROP TABLE IF EXISTS `pachet_promotional`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pachet_promotional` (
  `ID` varchar(5) NOT NULL,
  `nume` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `id_pachet_UNIQUE` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `sistem`
--

DROP TABLE IF EXISTS `sistem`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `sistem` (
  `ID` varchar(5) NOT NULL,
  `familie` varchar(45) DEFAULT NULL,
  `nume` varchar(45) DEFAULT NULL,
  `cantitate_comandata` int DEFAULT NULL,
  `cantitate_livrata` int DEFAULT NULL,
  `cantitate_inventar` int DEFAULT NULL,
  `id_livrare` varchar(5) DEFAULT NULL,
  `pret` float DEFAULT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `ID_sistem_UNIQUE` (`ID`),
  KEY `ID_livrare_fk_idx` (`id_livrare`),
  CONSTRAINT `ID_livrare_fk` FOREIGN KEY (`id_livrare`) REFERENCES `livrare` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-05-07 20:45:58
