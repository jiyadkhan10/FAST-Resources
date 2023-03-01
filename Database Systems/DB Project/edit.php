<?php

$link = mysqli_connect("localhost", "root", "", "db-project");

if($link == false)
{
   die("ERROR: Could not connect. " . mysqli_connect_error());
}

$ID = $_GET['toedit'];

if(isset($_POST['submit']))
{

$Name = $_POST['Name'];
$Age = $_POST['Age'];
$Gender = $_POST['Gender'];
$Course =  $_POST['Course'];
$MCNIC = $_POST['MCNIC'];
$FCNIC = $_POST['FCNIC'];
$GCNIC =  $_POST['GCNIC'];

$sql = "UPDATE student 
SET Student_ID = $ID,
Name = '$Name', 
Age = $Age, 
Gender = '$Gender', 
Class_ID = $Course,
MCNIC = $MCNIC, 
FCNIC = '$FCNIC', 
GCNIC = $GCNIC
WHERE Student_ID = $ID";


if(mysqli_query($link, $sql))
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


<html>
	<head>
		<title> Student Admission Form</title>

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

</style>

</head>

	<body>
		<center>
			<div class= "heading">
			<h1> Hamarey Bachchey <br> Record Update Form</h1>
		    </div>
		</center>

<br><br><br>

	<form method="post">

		<b style = "font-size:20px;"> Student Information: </b>

		<br>
		<br>
		<br>
		
		<b style = "font-size:20px;">Name</b> 
		<br>
		<br>
		<input type = "text", name = "Name", value="", placeholder= "Full name" required>  
		
		<br>
		<br> 
		<br>

		<b style = "font-size:20px;">Student's Age</b> 

		<br>
		<br>

		Age: <input type = "number", name = "Age", placeholder= "Age" required>  

		
		<br>
		<br> 
		<br>

		<b style = "font-size:20px;">Student's Gender</b> 

		<br>
		<br>

			Gender: <input type = "radio", name = "Gender", value = "Male"> Male 
					<input type = "radio", name = "Gender", value = "Female"> Female
					<input type = "radio", name = "Gender", value = "Other"> Other

		<br>
		<br>

		<b style = "font-size:20px;">Registered Class</b> 

		<br>
		<br>

		Class_ID: <input type = "text", name = "Course", placeholder= "Class ID" required>  

		
		<br>
		<br> 
		<br>

		Mother_CNIC: <input type = "text", name = "MCNIC", placeholder= "XXXXX-XXXXXXX-X" required>  

		
		<br>
		<br> 
		<br>

		Father_CNIC: <input type = "text", name = "FCNIC", placeholder= "XXXXX-XXXXXXX-X" required>  

		
		<br>
		<br> 
		<br>

		Guardian_CNIC: <input type = "text", name = "GCNIC", placeholder= "XXXXX-XXXXXXX-X" required>  

		<br>
		<br> 
		<br>

        <button type="submit" name="submit" class = "button"> Update </button>

        </form>
	</body>	
</html>