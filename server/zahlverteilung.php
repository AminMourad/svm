<?php

/*
handels distribution of the numbers the way the original settlers of catan does it by randomly selecting one ressource field on the outer rim and distributing the ordered numbers clockwise from there
also allows for the board to only show where to place the first number and the player being capable of placing all the others, which was necessitated by the 7-segment displays not working due to an error in wiring the controllers

lacking comments
*/



include_once 'sql/sql_connect.php';
	
	
function zahlverteilung($standard){
	
	global $conn;
	
	$zahlen = array(5,2,6,3,8,10,9,12,11,4,8,10,9,4,5,6,3,11);
	$szahlen = array(4,6,9,4,10,11,11,6,3,3,9,2,5,12,8,10,5,8);
	$schritt = array(0,13,14,14,15,15,16,16,17,17,18,18,13);
	
	if($standard==1){
		for($h=1; $h<19; $h++){
			$zahl=$szahlen[$h-1];
			$zahlQuery = "
					UPDATE feld
					SET zahl = $zahl
					WHERE feld_id = $h;";
			mysqli_query($conn, $zahlQuery);
		}
		return;
		
	}
	
	$aussen = random_int(1,12);
	$aussenend=12;
	$arraypos = 0;
	if($aussen>1){$aussenend = $aussen-1;};
	
	for($i=$aussen; $i<13; $i++){
		$zahl = $zahlen[$arraypos];
		$zahlQuery = "
					UPDATE feld
					SET zahl = $zahl
					WHERE feld_id = $i;";
					
		mysqli_query($conn, $zahlQuery);
		
		$arraypos++;
		
	}
	
	
	for ($j = 1; $j<$aussen; $j++){
		$zahl = $zahlen[$arraypos];
		$zahlQuery = "
					UPDATE feld
					SET zahl = $zahl
					WHERE feld_id = $j;";
					
		mysqli_query($conn, $zahlQuery);
		
		$arraypos++;
	}
	
	$innen = $schritt[$aussenend];
	
	for($k=$innen; $k<19; $k++){
		$zahl = $zahlen[$arraypos];
		$zahlQuery = "
					UPDATE feld
					SET zahl = $zahl
					WHERE feld_id = $k;";
					
		mysqli_query($conn, $zahlQuery);
		
		$arraypos++;
		
	}
	
	for ($l = 13; $l<$innen; $l++){
		$zahl = $zahlen[$arraypos];
		$zahlQuery = "
					UPDATE feld
					SET zahl = $zahl
					WHERE feld_id = $l;";
					
		mysqli_query($conn, $zahlQuery);

		$arraypos++;
	}
	return($aussen);
}