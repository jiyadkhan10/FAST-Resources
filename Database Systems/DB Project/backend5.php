<?php

$link = mysqli_connect("localhost", "root", "", "db-project");

if($link == false)
{
   die("ERROR: Could not connect. " . mysqli_connect_error());
}

//To input data in the student table

$ID = mysqli_real_escape_string($link, $_POST['ID']);
$AgeGroup = mysqli_real_escape_string($link, $_POST['Age-Group']);
$Section = mysqli_real_escape_string($link, $_POST['Section']);
$Title = mysqli_real_escape_string($link, $_POST['Title']);
$Gender = mysqli_real_escape_string($link, $_POST['Gender']);

$sql = "INSERT INTO class (Class_ID, Age_Group, Section, Title, Gender) 
VALUES ('$ID', '$AgeGroup', '$Section', '$Title', '$Gender')";

if(mysqli_query($link, $sql))
{
   echo "Data successfully saved for class."; 
}

else
{
   echo "ERROR: Could not able to execute $sql." . mysqli_error($link);
}