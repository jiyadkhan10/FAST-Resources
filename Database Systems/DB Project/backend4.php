<?php

$link = mysqli_connect("localhost", "root", "", "db-project");

if($link == false)
{
   die("ERROR: Could not connect. " . mysqli_connect_error());
}

//To input data in the student table

$Name = mysqli_real_escape_string($link, $_POST['FullName']);
$CIS = mysqli_real_escape_string($link, $_POST['CIS']);
$CNIC = mysqli_real_escape_string($link, $_POST['CNIC-Number']);
$Number = mysqli_real_escape_string($link, $_POST['Mobile-Number']);
$Email = mysqli_real_escape_string($link, $_POST['Email']);
$Address = mysqli_real_escape_string($link, $_POST['Address']);

$sql = "INSERT INTO staff (CNIC, Name, Children_in_School, Phone_number, Address, Email) 
VALUES ('$CNIC', '$Name', '$CIS', '$Number', '$Address',  '$Email')";

if(mysqli_query($link, $sql))
{
   echo "Data successfully saved for accompanying guardian."; 
}

else
{
   echo "ERROR: Could not able to execute $sql." . mysqli_error($link);
}