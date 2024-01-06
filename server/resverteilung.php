<?php
//Function for randomly distributing ressource fields


include_once 'sql/sql_connect.php';


function resverteilung($standard){

	global $conn;

	$ressourcen = array(4,1,4,5,5,1,3,4,4,1,5,2,1,5,3,2,3,2);

	if($standard != 1){shuffle($ressourcen);}

	for($i=0; $i<18; $i++){
		$setRes = $ressourcen[$i];
		$fid=$i+1;
		$resFeldQuery = "
			UPDATE feld
			SET ressource = $setRes
			WHERE feld_id = $fid;";
		
		mysqli_query($conn, $resFeldQuery);
	}
	return;
}