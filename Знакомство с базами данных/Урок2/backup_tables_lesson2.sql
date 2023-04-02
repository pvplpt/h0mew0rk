-- MySQL dump 10.19  Distrib 10.3.38-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: db_lesson2
-- ------------------------------------------------------
-- Server version	10.3.38-MariaDB-0+deb10u1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `addresses`
--

DROP TABLE IF EXISTS `addresses`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `addresses` (
  `whose_address` int(11) DEFAULT NULL,
  `address` varchar(100) DEFAULT NULL,
  `comment` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `addresses`
--

LOCK TABLES `addresses` WRITE;
/*!40000 ALTER TABLE `addresses` DISABLE KEYS */;
INSERT INTO `addresses` VALUES (1,'Можга','Место рождения'),(1,'Казань','По прописке'),(1,'Москва','Рабочий'),(2,'Санкт-Петербург','По прописке'),(3,'Москва','По прописке'),(4,'Белгород','По прописке'),(5,'Уфа','По прописке'),(6,'Сочи','По прописке'),(7,'Киров','Рабочий'),(8,'Владивосток','Место рождения'),(9,'Рязань','Рабочий'),(10,'Хабаровск','Место рождения');
/*!40000 ALTER TABLE `addresses` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `common_list`
--

DROP TABLE IF EXISTS `common_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `common_list` (
  `name` varchar(100) DEFAULT NULL,
  `birthday` date DEFAULT NULL,
  `status` varchar(100) DEFAULT NULL,
  `phone_number` int(11) DEFAULT NULL,
  `comment` varchar(100) DEFAULT NULL,
  `address` varchar(100) DEFAULT NULL,
  `party` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `common_list`
--

LOCK TABLES `common_list` WRITE;
/*!40000 ALTER TABLE `common_list` DISABLE KEYS */;
INSERT INTO `common_list` VALUES ('Иванов И. И.','1990-02-12','женат',126,'интернет','Можга','Работа'),('Иванов И. И.','1990-02-12','женат',127,'старый','Можга','Работа'),('Иванов И. И.','2001-09-18','холост',527,'личный','Санкт-Петербург','Школа'),('Петров П. П.','1983-04-23','женат',234,'личный','Москва','Родня'),('Петров П. П.','1983-04-24','женат',235,'рабочий','Москва','Родня'),('Васильев В. В.','1998-05-21','холост',456,'личный','Белгород','Друзья'),('Сидоров С.С.','2007-07-13','холост',643,'личный','Киров','Родня'),('Сидоров С.С.','2007-07-12','холост',654,'старый','Киров','Родня'),('Александров А.А.','1987-03-05','женат',412,'рабочий','Уфа','Друзья'),('Борисов Б.Б','1989-08-16','холост',723,'рабочий','Москва','Работа'),('Михайлов М.М.','1997-01-08','женат',876,'личный','Сочи','Университет'),('Михайлов М.М.','1997-01-08','женат',875,'рабочий','Сочи','Университет'),('Кириллов К.К.','1996-12-03','холост',933,'личный','Киров','Работа');
/*!40000 ALTER TABLE `common_list` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `people`
--

DROP TABLE IF EXISTS `people`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `people` (
  `id` int(11) DEFAULT NULL,
  `name` varchar(100) DEFAULT NULL,
  `birthday` date DEFAULT NULL,
  `status` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `people`
--

LOCK TABLES `people` WRITE;
/*!40000 ALTER TABLE `people` DISABLE KEYS */;
INSERT INTO `people` VALUES (1,'Иванов И. И.','1990-02-12','женат'),(2,'Иванов И. И.','2001-09-18','холост'),(3,'Петров П. П.','1983-04-23','женат'),(4,'Васильев В. В.','1998-05-21','холост'),(25,'Кузьмин К.К.','2020-05-21','холост');
/*!40000 ALTER TABLE `people` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `phones`
--

DROP TABLE IF EXISTS `phones`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `phones` (
  `whose_phone` int(11) DEFAULT NULL,
  `phone_number` int(11) DEFAULT NULL,
  `comment` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `phones`
--

LOCK TABLES `phones` WRITE;
/*!40000 ALTER TABLE `phones` DISABLE KEYS */;
INSERT INTO `phones` VALUES (1,123,'личный'),(1,124,'рабочий'),(1,125,'для поездок'),(1,126,'интернет'),(1,127,'старый'),(2,527,'личный'),(3,234,'личный'),(3,235,'рабочий'),(4,456,'личный'),(11,999,'личный'),(12,997,'рабочий'),(13,995,'личный'),(14,993,'для поездок'),(15,991,'для поездок');
/*!40000 ALTER TABLE `phones` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-04-02 23:35:38
