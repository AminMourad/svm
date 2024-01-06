<?php
/*
Handels the player check for the longest street. If accessed, the accessing player wins as they have checked they'd have the longest street and the question was triggered by them having enough points to win with it.
Was never checked if it works and lacks comments.

*/

	include_once 'sql/sql_connect.php';
	
	if(isset($_GET['s']) && isset($_GET['f'])){
		$s = $_GET['s'];
		$f = $_GET['f'];
	}else{exit(".-1,");}
	
	$nextRes = mysqli_query($conn, "SELECT amzug FROM etc;");
	$nextArr = mysqli_fetch_assoc($nextRes);
	$next = $nextArr['amzug'];
	
	$log = "log1";
	if($f<3){$log = "log2";}
	
	if($s){
		echo(".9,");
		$query = "
			INSERT INTO $log (aktion, farbe)
			VALUES (9,$f)";
	
	if(($f<3 && $next<3) || ($f>2 && $next>2)){
			echo(".1,");
			$query = "
			INSERT INTO $log (aktion, farbe)
			VALUES (12,$next);";
		}
	}else{
			echo(".2,");
			$query = "
			INSERT INTO $log (aktion, farbe)
			VALUES (11,$next);";
		}