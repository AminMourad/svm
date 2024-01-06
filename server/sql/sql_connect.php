<?php
//File for establishing a connection with the database

$servername = "localhost"; //change if sql host is different to files host
//Change following to your credentials
$username = "YOUR_SQL_USERNAME"; 
$password = "YOUR_SQL_PASSWORD";
$db = "YOUR_DB_NAME";

// Create connection
$conn = mysqli_connect($servername, $username, $password, $db);

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

?>