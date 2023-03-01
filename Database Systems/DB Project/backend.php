<?php

$link = mysqli_connect("localhost", "root", "", "db-project");

if($link == false)
{
   die("ERROR: Could not connect. " . mysqli_connect_error());
}

//To input data in the student table

$Name = mysqli_real_escape_string($link, $_POST['Name']);
$Age = mysqli_real_escape_string($link, $_POST['Age']);
$Gender = mysqli_real_escape_string($link, $_POST['Gender']);
$Course = mysqli_real_escape_string($link, $_POST['Course']);
$MCNIC = mysqli_real_escape_string($link,$_POST['mCNIC-Number']);
$FCNIC = mysqli_real_escape_string($link,$_POST['CNIC-Number']);
$GCNIC =  mysqli_real_escape_string($link,$_POST['GCNIC']);

$sql = "INSERT INTO student (Name, Age, Gender, Class_ID, MCNIC, FCNIC, GCNIC) VALUES ('$Name', '$Age', '$Gender', '$Course', '$MCNIC', '$FCNIC', '$GCNIC')";

if(mysqli_query($link, $sql))
{
   echo "Data successfully saved for student \n.";
   
}

else
{
   echo "ERROR: Could not able to execute $sql. \n" . mysqli_error($link);
   
}

//To input data in the father table

$FName = mysqli_real_escape_string($link, $_POST['FullName']);
$FCNIC = mysqli_real_escape_string($link, $_POST['CNIC-Number']);
$FNumber = mysqli_real_escape_string($link, $_POST['Mobile-Number']);
$FEmail = mysqli_real_escape_string($link, $_POST['Email']);
$FAddress = mysqli_real_escape_string($link, $_POST['faddress']);

$sqlf = "INSERT INTO father (CNIC, Name, Phone_number, Address, Email) VALUES ('$FCNIC', '$FName', '$FNumber', '$FAddress', '$FEmail')";

if(mysqli_query($link, $sqlf))
{
   echo "Data successfully saved for father.\n";
   
}

else
{
   echo "ERROR: Could not able to execute $sqlf. \n" . mysqli_error($link);
   
}

//To input data in the mother table

$MName = mysqli_real_escape_string($link, $_POST['mfullName']);
$MCNIC = mysqli_real_escape_string($link, $_POST['mCNIC-Number']);
$MNumber = mysqli_real_escape_string($link, $_POST['mMobile-Number']);
$MEmail = mysqli_real_escape_string($link, $_POST['mEmail']);
$MAddress = mysqli_real_escape_string($link, $_POST['mAddress']);

$sqlm = "INSERT INTO mother (CNIC, Name, Phone_number, Address, Email) VALUES ('$MCNIC', '$MName', '$MNumber', '$MAddress', '$MEmail')";

if(mysqli_query($link, $sqlm))
{
   echo "Data successfully saved for mother.\n";
}

else
{
   echo "ERROR: Could not able to execute $sqlm. \n" . mysqli_error($link);
}

//For fee Challan

$Challan = mysqli_real_escape_string($link, $_POST['Challan']);
$Fee = mysqli_real_escape_string($link, $_POST['Fee']);
$Discount = mysqli_real_escape_string($link, $_POST['Discount']);
$Status = mysqli_real_escape_string($link, $_POST['Status']);
$Date = mysqli_real_escape_string($link, $_POST['Date']);

$sqlm = "INSERT INTO fee (Challan_no, Total_Fee, Discount, Paid, date_submitted) VALUES ('$Challan', '$Fee', '$Discount', '$Status', '$Date')";

if(mysqli_query($link, $sqlm))
{
   echo "Data successfully saved for fee. \n";
}

else
{
   echo "ERROR: Could not able to execute $sqlm. \n" . mysqli_error($link);
}

// close connection
mysqli_close($link);
?>
