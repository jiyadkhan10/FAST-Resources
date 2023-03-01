<?php

$link = mysqli_connect("localhost", "root", "", "db-project");

if($link == false)
{
   die("ERROR: Could not connect. " . mysqli_connect_error());
}
else{
    echo "Successfully connected to db!";
}


if(isset($_GET['todelete']))
{
    $id = $_GET['todelete'];

    $sql = "DELETE FROM student WHERE Student_ID = $id";

    $result = mysqli_query($link,$sql);

    if($result)
    {
        header('location:mainbackend.php');
    }

    else
    {
        echo "Could not execute properly :(";
        die(mysqli_error($link));
    }
}



?>