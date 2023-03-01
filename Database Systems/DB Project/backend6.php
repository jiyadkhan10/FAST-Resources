<?php

$link = mysqli_connect("localhost", "root", "", "db-project");

if($link == false)
{
   die("ERROR: Could not connect. " . mysqli_connect_error());
}

//To input data in the student table

$CID = mysqli_real_escape_string($link, $_POST['CID']);
$ID = mysqli_real_escape_string($link, $_POST['ID']);
$Title = mysqli_real_escape_string($link, $_POST['Title']);

$sql = "INSERT INTO course (Course_ID, Class_ID, Course_Title) 
VALUES ('$CID', '$ID', '$Title')";

if(mysqli_query($link, $sql))
{
   echo "Data successfully saved for course."; 
}

else
{
   echo "ERROR: Could not able to execute $sql." . mysqli_error($link);
}