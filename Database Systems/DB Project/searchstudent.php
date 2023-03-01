<html>
	<head>
		<title> Search Student Form</title>

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
			<h1> Hamarey Bachchey <br> Student Search Form</h1>
		    </div>
		</center>

<br><br><br>

	<form method="post">

		<b style = "font-size:20px;"> Name of Student: </b>

		<br>
		<br>
		<br>

		Full Name: <input type = "text", name = "Name", placeholder= "Jiyad Khan" required>  

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

$Name = $_POST['Name'];

$sql = "SELECT s.Student_ID, s.Class_ID, s.Name, s.Age, s.Gender, f.CNIC, f.Name, f.Phone_number, f.Address, m.CNIC, m.Name, m.Phone_number, m.Address, g.CNIC, g.Name, g.Relationship, g.Phone_number, g.Address, c.Title, c.Section, c.Age_Group, COUNT(CASE WHEN s.FCNIC = ss.FCNIC AND s.Student_ID <> ss.Student_ID THEN 1 END) as 'Sibling'
FROM student s
JOIN student ss
JOIN father f
ON(s.Student_ID = f.Student_ID)
JOIN mother m
ON(s.Student_ID = m.Student_ID)
JOIN hist_guardian g
ON(s.Student_ID = g.Student_ID)
JOIN class c 
ON(s.Class_ID = c.Class_ID)
JOIN hist_parent hp
ON(s.Student_ID = hp.Student_ID)
WHERE s.Name LIKE '%$Name%'
GROUP BY s.Student_ID";

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