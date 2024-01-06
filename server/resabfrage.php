<?php
//Checking current ressource standings of players of a board


	include_once 'sql/sql_connect.php'; 
	
	if(isset($_GET['b'])){
		$b = $_GET['b'];
	}else{exit(".0,.,");}
	
	switch($b){
		case 1:
			$farben = "1 OR spieler_id = 2";
			break;
		case 2:
			$farben = "3 OR spieler_id = 4";
			break;
	}
	
	$selectQuery = "
			SELECT *
			FROM spieler
			WHERE spieler_id = $farben;";
			
	$res = mysqli_query($conn, $selectQuery);
	echo(".");
	while($row = mysqli_fetch_assoc($res)){
			echo implode(",",$row) . ",";
		}
	exit(".,");