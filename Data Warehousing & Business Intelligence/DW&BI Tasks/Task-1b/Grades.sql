CREATE DATABASE StdGrades;

USE `StdGrades`;
DROP TABLE IF EXISTS `students`;

CREATE TABLE `students` (
  `ID` int(11) NOT NULL,
  `Name` varchar(50) NOT NULL,
  `Marks` varchar(50) NOT NULL);
  
  insert  into `students`(`ID`, `Name`,`Marks`) values 
  (0, 'Monica', 64),
  (1, 'Jennifer', 77),
  (2,'Sarah',83),
  (3,'Joey', 87),
  (4,'Andrew',76),
  (5,'Mathew',61),
  (6, 'Jane',86),
  (7,'Antorio', 74),
  (8,'Chandler',55);
  
  
DROP TABLE IF EXISTS `grades`;

CREATE TABLE `grades` (
  `Grade` int(11) NOT NULL,
  `Min_Marks` varchar(50) NOT NULL,
  `Max_Marks` varchar(50) NOT NULL);
  
  insert  into `grades`(`Grade`,`Min_Marks`,`Max_Marks`) values 
  (2, 10, 19),
  (3, 20, 29),
  (4, 30, 39),
  (5, 40, 49),
  (6, 50, 59),
  (7, 60, 69),
  (8, 70, 79),
  (9, 80, 89),
  (10, 90, 100);
  