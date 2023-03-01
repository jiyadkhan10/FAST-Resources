<?php

$link = mysqli_connect("localhost", "root", "", "db-project");

if($link == false)
{
   die("ERROR: Could not connect. " . mysqli_connect_error());
}

//To input data in the student table

$Name = mysqli_real_escape_string($link, $_POST['FullName']);
$ID = mysqli_real_escape_string($link, $_POST['ID']);
$Age = mysqli_real_escape_string($link, $_POST['Age']);
$Gender = mysqli_real_escape_string($link, $_POST['Gender']);
$OClass = mysqli_real_escape_string($link, $_POST['Class']);
$NClass = mysqli_real_escape_string($link, $_POST['New-Class']);
$Reason = mysqli_real_escape_string($link, $_POST['Reason']);
$Approved_by = mysqli_real_escape_string($link, $_POST['Approved-by']);
$Date = mysqli_real_escape_string($link, $_POST['Date']);

$sql = "INSERT INTO class_assignment (Student_ID, Name, Age, Gender, Old_class, New_Class, Reason, Approved_By, Date) 
VALUES ('$ID', '$Name', '$Age', '$Gender', '$OClass', '$NClass', '$Reason', '$Approved_by', '$Date')";

if(mysqli_query($link, $sql))
{
   echo "Data successfully saved for class assignment."; 
}

else
{
   echo "ERROR: Could not able to execute $sql." . mysqli_error($link);
}