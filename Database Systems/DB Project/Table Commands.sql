Creating 13 tables.

1) CREATE TABLE `student` (
 `Student_ID` int(10) NOT NULL AUTO_INCREMENT,
 `Name` varchar(50) DEFAULT NULL,
 `Age` varchar(10) DEFAULT NULL,
 `Gender` varchar(30) DEFAULT NULL,
 `Class_ID` varchar(20) DEFAULT NULL,
 PRIMARY KEY (`Student_ID`),
 KEY `Class_ID` (`Class_ID`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=latin1

2) CREATE TABLE `staff` (
 `CNIC` varchar(20) NOT NULL,
 `Name` varchar(50) DEFAULT NULL,
 `Children_in_School` varchar(10) DEFAULT NULL,
 `Phone_number` varchar(20) DEFAULT NULL,
 `Address` varchar(200) DEFAULT NULL,
 `Email` varchar(50) DEFAULT NULL,
 PRIMARY KEY (`CNIC`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1

3) CREATE TABLE `mother` (
 `CNIC` varchar(20) NOT NULL,
 `Name` varchar(50) DEFAULT NULL,
 `Student_ID` int(10) NOT NULL AUTO_INCREMENT,
 `Phone_number` varchar(20) DEFAULT NULL,
 `Address` varchar(200) DEFAULT NULL,
 `Email` varchar(50) DEFAULT NULL,
 PRIMARY KEY (`Student_ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 

4) CREATE TABLE `hist_student` (
 `Student_ID` varchar(10) NOT NULL,
 `Name` varchar(50) DEFAULT NULL,
 `Age` varchar(30) DEFAULT NULL,
 `Gender` varchar(20) DEFAULT NULL,
 `Class_ID` varchar(20) DEFAULT NULL,
 PRIMARY KEY (`Student_ID`),
 KEY `hs_cid_fk` (`Class_ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1


5) CREATE TABLE `hist_parent` (
 `CNIC` varchar(20) NOT NULL,
 `Name` varchar(50) DEFAULT NULL,
 `Student_ID` int(30) NOT NULL AUTO_INCREMENT,
 `Phone_number` varchar(20) DEFAULT NULL,
 `Address` varchar(150) DEFAULT NULL,
 `Email` varchar(50) DEFAULT NULL,
 PRIMARY KEY (`Student_ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1

6) CREATE TABLE `hist_guardian` (
 `CNIC` varchar(20) NOT NULL,
 `Name` varchar(50) DEFAULT NULL,
 `Student_ID` int(30) NOT NULL AUTO_INCREMENT,
 `Relationship` varchar(20) DEFAULT NULL,
 `Phone_number` varchar(20) DEFAULT NULL,
 `Address` varchar(150) DEFAULT NULL,
 `Email` varchar(50) DEFAULT NULL,
 PRIMARY KEY (`Student_ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1


7) CREATE TABLE `guardian` (
 `CNIC` varchar(20) NOT NULL,
 `Name` varchar(50) DEFAULT NULL,
 `Student_ID` int(10) NOT NULL AUTO_INCREMENT,
 `Relationship` varchar(30) DEFAULT NULL,
 `Phone_number` varchar(20) DEFAULT NULL,
 `Address` varchar(200) DEFAULT NULL,
 `Email` varchar(50) DEFAULT NULL,
 PRIMARY KEY (`Student_ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1

8) CREATE TABLE `fee` (
 `Total_Fee` varchar(10) DEFAULT NULL,
 `Discount` varchar(10) DEFAULT NULL,
 `Paid` varchar(20) DEFAULT NULL,
 `Challan_no` varchar(30) NOT NULL,
 `date_submitted` date DEFAULT NULL,
 PRIMARY KEY (`Challan_no`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1


9) CREATE TABLE `father` (
 `CNIC` varchar(20) NOT NULL,
 `Name` varchar(50) DEFAULT NULL,
 `Student_ID` int(10) NOT NULL AUTO_INCREMENT,
 `Phone_number` varchar(20) DEFAULT NULL,
 `Address` varchar(200) DEFAULT NULL,
 `Email` varchar(50) DEFAULT NULL,
 PRIMARY KEY (`Student_ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1

10) CREATE TABLE `course` (
 `Course_ID` int(10) NOT NULL,
 `Class_ID` varchar(20) NOT NULL,
 `Course_Title` varchar(30) DEFAULT NULL,
 PRIMARY KEY (`Course_ID`),
 KEY `Class_ID` (`Class_ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1


11) CREATE TABLE `class` (
 `Class_ID` int(10) NOT NULL AUTO_INCREMENT,
 `Age_Group` varchar(20) DEFAULT NULL,
 `Section` varchar(10) DEFAULT NULL,
 `Title` varchar(30) DEFAULT NULL,
 `Gender` varchar(20) DEFAULT NULL,
 PRIMARY KEY (`Class_ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1

12)  CREATE TABLE `accompanying_guardian` (
 `CNIC` varchar(20) NOT NULL,
 `Name` varchar(50) DEFAULT NULL,
 `Student_ID` varchar(10) DEFAULT NULL,
 `Relationship` varchar(30) DEFAULT NULL,
 `Phone_number` varchar(20) DEFAULT NULL,
 `Address` varchar(200) DEFAULT NULL,
 `Email` varchar(50) DEFAULT NULL,
 `Assistance` varchar(150) DEFAULT NULL,
 PRIMARY KEY (`CNIC`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1

13) CREATE TABLE `class_assignment` (
 `Student_ID` int(20) NOT NULL,
 `Name` varchar(50) NOT NULL,
 `Age` varchar(20) NOT NULL,
 `Gender` varchar(10) NOT NULL,
 `Old_Class` varchar(30) NOT NULL,
 `New_Class` varchar(30) NOT NULL,
 `Reason` varchar(500) NOT NULL,
 `Approved_By` varchar(50) NOT NULL,
 `Date` date NOT NULL,
 PRIMARY KEY (`Student_ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1


Data Insertion into the Tables:

INSERT INTO  `student` (`Student_ID`, `Name`, `Age`, `Gender`, `Class_ID`, `MCNIC`, `FCNIC`, `GCNIC`)
VALUES (1, 'Jiyad Khan', 13, 'Male', 3, '35202-7232240-3', '35202-7232244-4', '45322-2343243-6');

INSERT INTO  `student` (`Student_ID`, `Name`, `Age`, `Gender`, `Class_ID`, `MCNIC`, `FCNIC`, `GCNIC`)
VALUES (2, 'Hareem Masood', 16, 'Female', 5, '35202-7232140-3', '35202-7232144-4', '45322-2343243-6');

INSERT INTO  `student` (`Student_ID`, `Name`, `Age`, `Gender`, `Class_ID`, `MCNIC`, `FCNIC`, `GCNIC`)
VALUES (3, 'Abdullah Faisal', 18, 'Male', 7, '35202-7232240-3', '35202-7232244-4', '45322-2343243-6');

INSERT INTO  `student` (`Student_ID`, `Name`, `Age`, `Gender`, `Class_ID`, `MCNIC`, `FCNIC`, `GCNIC`)
VALUES (4, 'Fatima Khan', 11, 'Female', 1, '35202-7232240-3', '35202-7232244-4', '45322-2343243-6');

INSERT INTO  `student` (`Student_ID`, `Name`, `Age`, `Gender`, `Class_ID`, `MCNIC`, `FCNIC`, `GCNIC`)
VALUES (5, 'Waleed Mukhtar', 10, 'Male', 1, '35202-7232241-3', '35202-7232241-4', '45322-2343267-6');


INSERT INTO  `staff` (`CNIC`, `Name`, `Children_in_School`, `Phone_number`, `Address`,`Email`)
VALUES ('12345-1234567-9', 'Jiyad Khan', 1, 0514905446, 'House # 290 - Street # 06 - Block C - Wah Cantt', 'jiyad@gmail.com');

INSERT INTO  `staff` (`CNIC`, `Name`, `Children_in_School`, `Phone_number`, `Address`,`Email`)
VALUES ('13254-1325476-4', 'Haris Usman', 2, 0513254768, 'House # 132 - Street # 07 - Block B - Islamabad', 'haris@gmail.com');

INSERT INTO  `staff` (`CNIC`, `Name`, `Children_in_School`, `Phone_number`, `Address`,`Email`)
VALUES ('54321-7654321-7', 'Saad Bhatti', 3, 0514247806, 'House # 333 - Street # 11 - Block A - Lahore', 'saad@gmail.com');

INSERT INTO  `staff` (`CNIC`, `Name`, `Children_in_School`, `Phone_number`, `Address`,`Email`)
VALUES ('45879-3246751-3', 'Sajid Khan', 4, 0512345678, 'House # 790 - Street # 77 - Block R - Karachi', 'sajid@gmail.com');

INSERT INTO  `staff` (`CNIC`, `Name`, `Children_in_School`, `Phone_number`, `Address`,`Email`)
VALUES ('32456-6743216-8', 'Ahmed Wadood', 5, 0513216547, 'House # 210 - Street # 22 - Block D - Islamabad', 'ahmed@gmail.com');


INSERT INTO `father` (`CNIC`, `Name`, `Student_ID`, `Phone_number`, `Address`, `Email`)
VALUES ('61101-5555555-6', 'Wajahat Ali Khan', 1, 03231111111, 'House # 290 - Street # 06 - Block C - Wah Cantt', 'wajahat@gmail.com');

INSERT INTO `father` (`CNIC`, `Name`, `Student_ID`, `Phone_number`, `Address`, `Email`)
VALUES ('71101-6666666-4', 'Ali Khan', 2, 03152222222, 'House # 132 - Street # 07 - Block B - Islamabad', 'ali@gmail.com');

INSERT INTO `father` (`CNIC`, `Name`, `Student_ID`, `Phone_number`, `Address`, `Email`)
VALUES ('81101-7777777-3', 'Ahmed Butt', 3, 03163333333, 'House # 333 - Street # 11 - Block A - Lahore', 'ahmed@gmail.com');

INSERT INTO `father` (`CNIC`, `Name`, `Student_ID`, `Phone_number`, `Address`, `Email`)
VALUES ('91101-8888888-2', 'Salman Khan', 4, 03304444444, 'House # 790 - Street # 77 - Block R - Karachi', 'salman@gmail.com');

INSERT INTO `father` (`CNIC`, `Name`, `Student_ID`, `Phone_number`, `Address`, `Email`)
VALUES ('31101-9999999-1', 'Usman Raza', 5, 03215555555, 'House # 210 - Street # 22 - Block D - Islamabad', 'usman@gmail.com');


INSERT INTO `mother` (`CNIC`, `Name`, `Student_ID`, `Phone_number`, `Address`, `Email`)
VALUES ('32456-2323232-3', 'Naheed Naser', 1, 03235708439, 'House # 290 - Street # 06 - Block C - Wah Cantt', 'naheed@gmail.com');

INSERT INTO `mother` (`CNIC`, `Name`, `Student_ID`, `Phone_number`, `Address`, `Email`)
VALUES ('11111-2343213-4', 'Sana ILyas', 2, 03100783040, 'House # 132 - Street # 07 - Block B - Islamabad', 'sana@gmail.com');

INSERT INTO `mother` (`CNIC`, `Name`, `Student_ID`, `Phone_number`, `Address`, `Email`)
VALUES ('22222-1111111-5', 'Zoya Imran', 3, 03238556117, 'House # 333 - Street # 11 - Block A - Lahore', 'zoya@gmail.com');

INSERT INTO `mother` (`CNIC`, `Name`, `Student_ID`, `Phone_number`, `Address`, `Email`)
VALUES ('33333-2222222-6', 'Saman Sajid', 4, 03185189409, 'House # 790 - Street # 77 - Block R - Karachi', 'saman@gmail.com');

INSERT INTO `mother` (`CNIC`, `Name`, `Student_ID`, `Phone_number`, `Address`, `Email`)
VALUES ('44444-3333333-7', 'Ramsha Zain', 5, 03235000000, 'House # 210 - Street # 22 - Block D - Islamabad', 'ramsha@gmail.com');


INSERT INTO  `hist_student` (`Student_ID`, `Name`, `Age`, `Gender`, `Class_ID`, `MCNIC`, `FCNIC`, `GCNIC`)
VALUES (1, 'Jiyad Khan', 13, 'Male', 1, '35202-7232240-3', '35202-7232244-4', '45322-2343243-6');

INSERT INTO  `hist_student` (`Student_ID`, `Name`, `Age`, `Gender`, `Class_ID`, `MCNIC`, `FCNIC`, `GCNIC`)
VALUES (2, 'Hareem Masood', 16, 'Female', 2, '35202-7232140-3', '35202-7232144-4', '45322-2343243-6');

INSERT INTO  `hist_student` (`Student_ID`, `Name`, `Age`, `Gender`, `Class_ID`, `MCNIC`, `FCNIC`, `GCNIC`)
VALUES (3, 'Abdullah Faisal', 18, 'Male', 3, '35202-7232240-3', '35202-7232244-4', '45322-2343243-6');

INSERT INTO  `hist_student` (`Student_ID`, `Name`, `Age`, `Gender`, `Class_ID`, `MCNIC`, `FCNIC`, `GCNIC`)
VALUES (4, 'Fatima Khan', 11, 'Female', 4, '35202-7232240-3', '35202-7232244-4', '45322-2343243-6');

INSERT INTO  `hist_student` (`Student_ID`, `Name`, `Age`, `Gender`, `Class_ID`, `MCNIC`, `FCNIC`, `GCNIC`)
VALUES (5, 'Waleed Mukhtar', 10, 'Male', 5, '35202-7232241-3', '35202-7232241-4', '45322-2343267-6');


INSERT INTO `hist_parent` (`CNIC`, `Name`, `Student_ID`, `Phone_number`, `Address`, `Email`)
VALUES ('61101-5555555-6', 'Wajahat Ali Khan', 1, 03231111111, 'House # 290 - Street # 06 - Block C - Wah Cantt', 'wajahat@gmail.com');

INSERT INTO `hist_parent` (`CNIC`, `Name`, `Student_ID`, `Phone_number`, `Address`, `Email`)
VALUES ('71101-6666666-4', 'Ali Khan', 2, 03152222222, 'House # 132 - Street # 07 - Block B - Islamabad', 'ali@gmail.com');

INSERT INTO `hist_parent` (`CNIC`, `Name`, `Student_ID`, `Phone_number`, `Address`, `Email`)
VALUES ('81101-7777777-3', 'Ahmed Butt', 3, 03163333333, 'House # 333 - Street # 11 - Block A - Lahore', 'ahmed@gmail.com');

INSERT INTO `hist_parent` (`CNIC`, `Name`, `Student_ID`, `Phone_number`, `Address`, `Email`)
VALUES ('91101-8888888-2', 'Salman Khan', 4, 03304444444, 'House # 790 - Street # 77 - Block R - Karachi', 'salman@gmail.com');

INSERT INTO `hist_parent` (`CNIC`, `Name`, `Student_ID`, `Phone_number`, `Address`, `Email`)
VALUES ('31101-9999999-1', 'Usman Raza', 5, 03215555555, 'House # 210 - Street # 22 - Block D - Islamabad', 'usman@gmail.com');


INSERT INTO `guardian` (`CNIC`, `Name`, `Student_ID`, `Relationship`, `Phone_number`, `Address`, `Email`)
VALUES ('11101-2345678-4', 'Ahmed Khan ', 1, 03234545456, 'Uncle', 'House # 20 - Street # 16 - Block F - Islamabad', 'ahmed10@gmail.com');

INSERT INTO `guardian` (`CNIC`, `Name`, `Student_ID`, `Relationship`, `Phone_number`, `Address`, `Email`)
VALUES ('21101-3434345-4', 'Ayesha Shakeel', 2, 03203232321, 'Aunt', 'House # 22 - Street # 77 - Block R - Rawalpindi', 'ayesha_shakeel@gmail.com');

INSERT INTO `guardian` (`CNIC`, `Name`, `Student_ID`, `Relationship`, `Phone_number`, `Address`, `Email`)
VALUES ('13101-7676768-4', 'Raza Ali', 3, 03001212134, 'GrandFather', 'House # 03 - Street # 17 - Block C - Lahore', 'raza_ali@gmail.com');

INSERT INTO `guardian` (`CNIC`, `Name`, `Student_ID`, `Relationship`, `Phone_number`, `Address`, `Email`)
VALUES ('41101-3222222-4', 'Sana Khan', 4, 03356789779, 'Aunt', 'House # 70 - Street # 27 - Block C - Karachi', 'sana@gmail.com');

INSERT INTO `guardian` (`CNIC`, `Name`, `Student_ID`, `Relationship`, `Phone_number`, `Address`, `Email`)
VALUES ('51101-2233445-4', 'Ali Raza', 5, 03243456790, 'Uncle', 'House # 21 - Street # 62 - Block D - Attock', 'ali_raza@gmail.com');


INSERT INTO `hist_guardian` (`CNIC`, `Name`, `Student_ID`, `Relationship`, `Phone_number`, `Address`, `Email`)
VALUES ('11101-2345678-4', 'Ahmed Khan ', 1, 03234545456, 'Uncle', 'House # 20 - Street # 16 - Block F - Islamabad', 'ahmed10@gmail.com');

INSERT INTO `hist_guardian` (`CNIC`, `Name`, `Student_ID`, `Relationship`, `Phone_number`, `Address`, `Email`)
VALUES ('21101-3434345-4', 'Ayesha Shakeel', 2, 03203232321, 'Aunt', 'House # 22 - Street # 77 - Block R - Rawalpindi', 'ayesha_shakeel@gmail.com');

INSERT INTO `hist_guardian` (`CNIC`, `Name`, `Student_ID`, `Relationship`, `Phone_number`, `Address`, `Email`)
VALUES ('13101-7676768-4', 'Raza Ali', 3, 03001212134, 'GrandFather', 'House # 03 - Street # 17 - Block C - Lahore', 'raza_ali@gmail.com');

INSERT INTO `hist_guardian` (`CNIC`, `Name`, `Student_ID`, `Relationship`, `Phone_number`, `Address`, `Email`)
VALUES ('41101-3222222-4', 'Sana Khan', 4, 03356789779, 'Aunt', 'House # 70 - Street # 27 - Block C - Karachi', 'sana@gmail.com');

INSERT INTO `hist_guardian` (`CNIC`, `Name`, `Student_ID`, `Relationship`, `Phone_number`, `Address`, `Email`)
VALUES ('51101-2233445-4', 'Ali Raza', 5, 03243456790, 'Uncle', 'House # 21 - Street # 62 - Block D - Attock', 'ali_raza@gmail.com');


INSERT INTO `fee` (`Total_Fee`, `Discount`, `Paid`, `Challan_no`, `date_submitted`)
VALUES(20000, 0, 'Yes', 01, STR_TO_DATE('04/11/2020', '%d/%m/%Y'));

INSERT INTO `fee` (`Total_Fee`, `Discount`, `Paid`, `Challan_no`, `date_submitted`)
VALUES(50000, 10000, 'Yes', 02, STR_TO_DATE('12/05/2021', '%d/%m/%Y'));

INSERT INTO `fee` (`Total_Fee`, `Discount`, `Paid`, `Challan_no`, `date_submitted`)
VALUES(15000, 5000, 'No', 03, STR_TO_DATE('23/10/2019', '%d/%m/%Y'));

INSERT INTO `fee` (`Total_Fee`, `Discount`, `Paid`, `Challan_no`, `date_submitted`)
VALUES(7000, 2000, 'Yes', 04, STR_TO_DATE('22/02/2021', '%d/%m/%Y'));

INSERT INTO `fee` (`Total_Fee`, `Discount`, `Paid`, `Challan_no`, `date_submitted`)
VALUES(10000, 0, 'No', 05, STR_TO_DATE('10/04/2020', '%d/%m/%Y'));


INSERT INTO `course` (`Course_ID`, `Class_ID`, `Course_Title`)
VALUES(01, 'DS-103', 'Database Systems');

INSERT INTO `course` (`Course_ID`, `Class_ID`, `Course_Title`)
VALUES(02, 'CS-104', 'Operating Systems');

INSERT INTO `course` (`Course_ID`, `Class_ID`, `Course_Title`)
VALUES(03, 'CS-103', 'Data Structures');

INSERT INTO `course` (`Course_ID`, `Class_ID`, `Course_Title`)
VALUES(04, 'CS-102', 'Object Oriented Programming');

INSERT INTO `course` (`Course_ID`, `Class_ID`, `Course_Title`)
VALUES(05, 'DS-101', 'Big Data');


INSERT INTO `class` (`Class_ID`, `Age_Group`, `Section`, `Title`, `Gender`)
VALUES(1, 13, 'A', 'MSA', 'Male');

INSERT INTO `class` (`Class_ID`, `Age_Group`, `Section`, `Title`, `Gender`)
VALUES(2, 16, 'B', 'MSB', 'Female');

INSERT INTO `class` (`Class_ID`, `Age_Group`, `Section`, `Title`, `Gender`)
VALUES(3, 18, 'C', 'MSC', 'Male');

INSERT INTO `class` (`Class_ID`, `Age_Group`, `Section`, `Title`, `Gender`)
VALUES(4, 11, 'D', 'MSD', 'Female');

INSERT INTO `class` (`Class_ID`, `Age_Group`, `Section`, `Title`, `Gender`)
VALUES(5, 10, 'E', 'MSE', 'Male');


INSERT INTO `accompanying_guardian` (`CNIC`, `Name`, `Student_ID`, `Relationship`, `Phone_number`, `Address`, `Email`, `Assistance`)
VALUES ('11101-2345678-4', 'Ahmed Khan ', 1, 03234545456, 'Uncle', 'House # 20 - Street # 16 - Block F - Islamabad', 'ahmed10@gmail.com', 'Need Assistance with Fee Challan of the Student');

INSERT INTO `accompanying_guardian` (`CNIC`, `Name`, `Student_ID`, `Relationship`, `Phone_number`, `Address`, `Email`, `Assistance`)
VALUES ('21101-3434345-4', 'Ayesha Shakeel', 2, 03203232321, 'Aunt', 'House # 22 - Street # 77 - Block R - Rawalpindi', 'ayesha_shakeel@gmail.com', 'Need Assistance with Parnet Teacher Meeting of the Student');

INSERT INTO `accompanying_guardian` (`CNIC`, `Name`, `Student_ID`, `Relationship`, `Phone_number`, `Address`, `Email`, `Assistance`)
VALUES ('13101-7676768-4', 'Raza Ali', 3, 03001212134, 'GrandFather', 'House # 03 - Street # 17 - Block C - Lahore', 'raza_ali@gmail.com', 'Need Assistance with Event of the Student');

INSERT INTO `accompanying_guardian` (`CNIC`, `Name`, `Student_ID`, `Relationship`, `Phone_number`, `Address`, `Email`, `Assistance`)
VALUES ('41101-3222222-4', 'Sana Khan', 4, 03356789779, 'Aunt', 'House # 70 - Street # 27 - Block C - Karachi', 'sana@gmail.com', 'Need Assistance with Fee Challan of the Student');

INSERT INTO `accompanying_guardian` (`CNIC`, `Name`, `Student_ID`, `Relationship`, `Phone_number`, `Address`, `Email`, `Assistance`)
VALUES ('51101-2233445-4', 'Ali Raza', 5, 03243456790, 'Uncle', 'House # 21 - Street # 62 - Block D - Attock', 'ali_raza@gmail.com', 'Need Assistance with Class Change of the Student');
