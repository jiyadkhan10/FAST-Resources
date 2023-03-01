<html>
	<head>
		<title> School Dormant Form</title>

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
			<h1> Hamarey Bachchey <br> Dormancy Check Form</h1>
		    </div>
		</center>

<br><br><br>

	<form method="post">

		<b style = "font-size:20px;"> Select Time Since Dormant: </b>

		<br>
		<br>
		<br>

		Time: <input type = "text", name = "Time", placeholder= "6 MONTH" required>  

        <button type="submit" name="submit" class = "button"> Search </button>

        </form>
	</body>	
</html>


<?php

$link = mysqli_connect("localhost", "root", "", "db-project");

if($link == false)
{
   die("ERROR: Could not connect. " . mysqli_connect_error());
}

if(isset($_POST['submit']))
{

$Time = $_POST['Time'];

$sql = "SELECT Student_ID AS ID, Name 
FROM student s
JOIN fee f
ON(s.Class_ID = f.Challan_no)
WHERE date_submitted < Now() and date_submitted < DATE_ADD(Now(), INTERVAL- $Time);";

$result = mysqli_query($link, $sql);

echo "Basic Report:";

echo "<br>";

while($row = mysqli_fetch_assoc($result))
{
  echo "<br>";
    foreach ($row as $field => $value) 
    {
     echo "<br>" . "<td>" . $value . "</td>" . "</br"; 
    }
    echo "<br>";
}
 
}
else
{
 echo "Failed to connect to Database";
 die("Ded");
}
?>