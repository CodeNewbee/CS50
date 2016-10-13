-- MySQL dump 10.13  Distrib 5.5.49, for debian-linux-gnu (x86_64)
--
-- Host: 0.0.0.0    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.49-0ubuntu0.14.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `trans_type` varchar(10) NOT NULL,
  `amount` int(20) NOT NULL,
  `symbol` varchar(10) NOT NULL,
  `user_id` int(10) unsigned NOT NULL,
  `time` datetime NOT NULL,
  `price` decimal(65,4) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=38 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES (26,'buy',19,'FCX',9,'2016-09-20 11:24:28',190.1900),(27,'sell',49,'FCX',9,'2016-09-20 11:24:33',490.4900),(28,'buy',200,'FCX',9,'2016-09-20 11:24:57',2002.0000),(29,'sell',200,'FCX',9,'2016-09-20 11:25:04',2002.0000),(30,'buy',12,'FREE',12,'2016-09-20 11:25:53',13.8000),(31,'sell',12,'FREE',12,'2016-09-20 11:25:56',13.8000),(32,'buy',20,'FCX',12,'2016-09-20 12:02:04',200.2000),(33,'buy',100,'FREE',11,'2016-09-24 06:42:43',115.0000),(34,'sell',100,'FREE',11,'2016-09-24 06:48:22',115.0000),(35,'buy',12,'FREE',11,'2016-09-24 06:48:34',13.8000),(36,'buy',142,'FCX',11,'2016-09-24 06:48:42',1509.4600),(37,'sell',142,'FCX',11,'2016-09-24 06:48:45',1509.4600);
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `stocks`
--

DROP TABLE IF EXISTS `stocks`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `stocks` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(10) unsigned NOT NULL,
  `symbol` varchar(10) NOT NULL,
  `shares` int(16) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `user_id` (`user_id`,`symbol`)
) ENGINE=InnoDB AUTO_INCREMENT=51 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `stocks`
--

LOCK TABLES `stocks` WRITE;
/*!40000 ALTER TABLE `stocks` DISABLE KEYS */;
INSERT INTO `stocks` VALUES (1,1,'NVAX',2),(2,2,'NVAX',2),(3,3,'NVAX',2),(4,4,'NVAX',2),(5,5,'NVAX',2),(6,6,'NVAX',2),(7,7,'NVAX',2),(8,8,'NVAX',2),(10,10,'NVAX',2),(47,12,'FCX',20),(49,11,'FREE',12);
/*!40000 ALTER TABLE `stocks` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `cash` decimal(65,4) unsigned NOT NULL DEFAULT '0.0000',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'andi','$2y$10$iLIU.2/JVNv27vTdrDLkrOB77Mjb.s4UIkp6ntwMEtFKjW6zn9hoe',10000.0000),(2,'caesar','$2y$10$iLIU.2/JVNv27vTdrDLkrOB77Mjb.s4UIkp6ntwMEtFKjW6zn9hoe',10000.0000),(3,'eli','$2y$10$iLIU.2/JVNv27vTdrDLkrOB77Mjb.s4UIkp6ntwMEtFKjW6zn9hoe',10000.0000),(4,'hdan','$2y$10$iLIU.2/JVNv27vTdrDLkrOB77Mjb.s4UIkp6ntwMEtFKjW6zn9hoe',10000.0000),(5,'jason','$2y$10$iLIU.2/JVNv27vTdrDLkrOB77Mjb.s4UIkp6ntwMEtFKjW6zn9hoe',10000.0000),(6,'john','$2y$10$iLIU.2/JVNv27vTdrDLkrOB77Mjb.s4UIkp6ntwMEtFKjW6zn9hoe',10000.0000),(7,'levatich','$2y$10$iLIU.2/JVNv27vTdrDLkrOB77Mjb.s4UIkp6ntwMEtFKjW6zn9hoe',10000.0000),(8,'rob','$2y$10$iLIU.2/JVNv27vTdrDLkrOB77Mjb.s4UIkp6ntwMEtFKjW6zn9hoe',10000.0000),(9,'skroob','$2y$10$iLIU.2/JVNv27vTdrDLkrOB77Mjb.s4UIkp6ntwMEtFKjW6zn9hoe',9556.4000),(10,'zamyla','$2y$10$iLIU.2/JVNv27vTdrDLkrOB77Mjb.s4UIkp6ntwMEtFKjW6zn9hoe',10000.0000),(11,'test','$2y$10$LyjHhhsD/VTSIZ84rOlhw.1o7Qg7MhQmnfefhRoK0kHXi0UhixuHK',9986.2000),(12,'test123','$2y$10$iLIU.2/JVNv27vTdrDLkrOB77Mjb.s4UIkp6ntwMEtFKjW6zn9hoe',9799.8000);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-09-24  7:54:44
