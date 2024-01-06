<?php

/*
	handels the ending of a turn, including checks if the game is over
*/

	include_once 'sql/sql_connect.php';

	if(isset($_GET['f'])){
			$farbe_p = $_GET['f'];
		}else{
		$farbeQuery = "
				SELECT amzug
				FROM etc;";
		$farbeRes = mysqli_query($conn, $farbeQuery);
		$farbeArr = mysqli_fetch_assoc($farbeRes);
		$farbe_p  = $farbeArr['amzug'];
		}

	//check if player won
	$log = 'log1';
	if($farbe_p<3){$log = 'log2';}
	
	$spQuery = "
			SELECT siegpunkt
			FROM spieler
			WHERE spieler_id = $farbe_p;";
	$spRes = mysqli_query($conn,$spQuery);
	$spArr = mysqli_fetch_assoc($spRes);
	
	//if player has 8 or 9 normal victory points, he wins by having either the largest army, or the longest road. With 6 or 7 he wins with both
	switch($spArr['siegpunkt']){
		case 6:
		case 7:
			$rmQuery = "
				SELECT rittermacht
				FROM etc
				WHERE rittermacht = $farbe_p;";
			$rmRes = mysqli_query($conn,$rmQuery);
			if(mysqli_num_rows($rmRes)){			//if player has largest army, mark for longest street check, otherwise move on
				$ssieg=1;
				break;
			}else{
				$ssieg=0;
				break;
			}
		case 8:
		case 9:
			$rmQuery = "
				SELECT rittermacht
				FROM etc
				WHERE rittermacht = $farbe_p;";
			$rmRes = mysqli_query($conn,$rmQuery);
			if(mysqli_num_rows($rmRes)){			//if player has largest army move to win, otherwise mark player for longest street check
			}else{
				$ssieg=1;
				break;
			}
		case 10:
			$logQuery = "
			INSERT INTO $log (aktion, farbe)
			VALUES (9,$farbe_p)";
			mysqli_query($conn,$logQuery);
			exit(".9,");
			break;
		default:
			$ssieg = 0;
			break;
	}

	
	
	//set next player and give back necessary feedback to check for longest street
	
	
	$anzahlSpielerRes = mysqli_query($conn,"SELECT spieler_id FROM spieler;");

	$anzahlSpieler = mysqli_num_rows($anzahlSpielerRes);
	
	$posQuery = "
			SELECT reihenfolge
			FROM spieler
			WHERE spieler_id = $farbe_p;";
	$posRes =  mysqli_query($conn,$posQuery);
	$posArr = mysqli_fetch_assoc($posRes);
	$reihenfolge = $posArr['reihenfolge'];
	
	if($reihenfolge < $anzahlSpieler){
		$next = $reihenfolge + 1;
	}else{
		$next = 1;
	}
	
	$nextQuery = "
			SELECT spieler_id
			FROM spieler
			WHERE reihenfolge = $next;";
	$nextRes = mysqli_query($conn,$nextQuery);
	$nextArr = mysqli_fetch_assoc($nextRes);
	$nextSpieler = $nextArr['spieler_id'];

	$zugQuery = array("
			UPDATE etc
			SET amzug = $nextSpieler;");
	
	if(($farbe_p<3 && $nextSpieler<3) || ($farbe_p>2 && $nextSpieler>2)){
		if($ssieg){
			echo(".3,");
		}else{
			echo(".4,");
			$zugQuery[] = "
			INSERT INTO $log (aktion, farbe)
			VALUES (12,$nextSpieler);";
		}
	}else{
		if($ssieg){
			echo(".5,");
		}else{
			echo(".6,");
			$zugQuery[] = "
			INSERT INTO $log (aktion, farbe)
			VALUES (11,$nextSpieler);";
		}
		
	}
	
	foreach ($zugQuery as $query) {
		mysqli_query($conn, $query);
	}
