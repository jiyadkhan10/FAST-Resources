<?php

$link = mysqli_connect("localhost", "root", "", "db-project");

if($link == false)
{
   die("ERROR: Could not connect. " . mysqli_connect_error());
}

//To input data in the student table

$SName = mysqli_real_escape_string($link, $_POST['Fullname']);
$ID = mysqli_real_escape_string($link, $_POST['ID']);
$CNIC = mysqli_real_escape_string($link, $_POST['CNIC-Number']);
$Relationship = mysqli_real_escape_string($link, $_POST['Relationship']);
$GName = mysqli_real_escape_string($link, $_POST['GFullName']);
$Number = mysqli_real_escape_string($link, $_POST['Mobile-Number']);
$Email = mysqli_real_escape_string($link, $_POST['Email']);
$Address = mysqli_real_escape_string($link, $_POST['gaddress']);
$Assistance = mysqli_real_escape_string($link, $_POST['assistance']);
$Reason = mysqli_real_escape_string($link, $_POST['reason']);

$sql = "INSERT INTO accompanying_guardian (CNIC, Name, Student_ID, Relationship, Phone_number, Address, Email, Assistance, Student_Name, Absence_Reason) 
VALUES ('$CNIC', '$GName', '$ID', '$Relationship', '$Number', '$Address',  '$Email', '$Assistance', '$SName', '$Reason')";

if(mysqli_query($link, $sql))
{
   echo "Data successfully saved for accompanying guardian."; 
}

else
{
   echo "ERROR: Could not able to execute $sql." . mysqli_error($link);
}