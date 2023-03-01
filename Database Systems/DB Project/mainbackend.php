<html>
	<head>
		<title>Project GUI</title>

		<script src="https://code.jquery.com/jquery-3.5.1.min.js"></script>
		<script type="text/javascript" src="//static.mailerlite.com/js/w/button.min.js?veb3acdd46bf692c067c6a9fe9fbc07d6"></script>

<script>
    function previewFile(input){
        var file = $("input[type=file]").get(0).files[0];
 
        if(file){
            var reader = new FileReader();
 
            reader.onload = function(){
                $("#previewImg").attr("src", reader.result);
            }
 
            reader.readAsDataURL(file);
        }
    }
</script>

<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css">

<style>
body{
  background-color: rgb(148, 139, 165);
  transition:background-color 0.5s ease;
}

button {
  background-color: #31ad6f; 
  border: none;
  color: white;
  padding: 15px 32px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 16px;
  margin: 4px 2px;
  cursor: pointer;
}

.heading {
background-color: black;
color: rgb(150, 47, 119);
text-align: center;
margin: 10px 400px;
}

.bt1{
  background-color: blue; 
  border: none;
  color: white;
  padding: 15px 32px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 12px;
  margin: 2px 1px;
  cursor: pointer;
}

.bt2{
  
  background-color: red; 
  border: none;
  color: white;
  padding: 15px 32px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 12px;
  margin: 2px 1px;
  cursor: pointer;
}

.button-1{
  background-color:  #31ad6f; 
  border: none;
  color: white;
  padding: 15px 32px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 12px;
  margin: 2px 1px;
  cursor: pointer;
}

.edit{
  color: white;
}

.delete{
  color: white;
}

.Add{
  color: white;
}

</style>

</head>

	<body>
		<center>
			<div class= "heading">
			<h1> Hamarey Bachchey <br> Students per Class Form</h1>
		    </div>
		</center>

<br><br><br>

<div class = "container">
  <button class = "button-1"><a href="SAF.html" class = "Add">Add +</a>
</button>

<table class = "table">

<tbody>

<?php

$link = mysqli_connect("localhost", "root", "", "db-project");

if($link == false)
{
   die("ERROR: Could not connect. " . mysqli_connect_error());
}

$sql = "SELECT * FROM student ORDER BY Class_ID";

$result = mysqli_query($link, $sql);

if($result)
{
  while($row = mysqli_fetch_assoc($result))
  {
    //echo '<br>';
    
    $Class = $row['Class_ID'];
    $ID = $row['Student_ID'];
    $Name = $row['Name'];
    $Age = $row['Age'];
    $Gender = $row['Gender'];

    echo '<tr>
    <th> Class:  '.$Class.' </th>
    <th> ID:  '.$ID.' </th>
    <td> Name: '.$Name.' </td>
    <td> Age: '.$Age.' </td>
    <td> Gender: '.$Gender.' </td>   

    <td> <button class = "bt1"><a href="edit.php?toedit='.$ID.'" class = "edit">Edit</a></button>
    <button class = "bt2"><a href="delete.php?todelete='.$ID.'" class = "delete">Delete</a></button></td>
    
    <tr>';
  }
}
?>
</tbody>

</table>

</div>