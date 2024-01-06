<?php
/*
Returns given log entry to board
	
	
*/



	include_once 'sql/sql_connect.php'; 
	
	echo(".");

	if(isset($_GET['b']) && $_GET['nr']){
		$b = $_GET['b'];
		$nr = $_GET['nr'];
	}else{exit(".,");};
	
	$lognr = "log$b";
	
	$logQuery = "
			SELECT aktion,pos,augenzahl,farbe,res
			FROM $lognr
			WHERE log_id = $nr;";
	
	$res = mysqli_query($conn, $logQuery);
	
	if(mysqli_num_rows($res)<1){
		exit("0,.,");	
	}
	
	$row = mysqli_fetch_assoc($res);
	
	echo implode(",",$row) . ",.,";