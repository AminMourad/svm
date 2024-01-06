<?php
/*
Handels moving the robber
*/


	include_once 'sql/sql_connect.php'; 
	
	
	if(isset($_GET['r']) && $_GET['r']<20 && $_GET['r']>0){
		$rPos = $_GET['r'];
	}else{exit(".-1,.,");};
	
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
	
	//Checking where robber is currently
	$abfrageQuery  = "
				SELECT feld_id
				FROM feld
				WHERE raeuber = 1;";
				
	$resAbfrage = mysqli_query($conn, $abfrageQuery);
	$rPosAltArr = mysqli_fetch_assoc($resAbfrage);
	
	$rPosAlt = $rPosAltArr['feld_id'];
	
	
	
	//Updating databse with current robber field
	
	$log = "log1";
	if($farbe_p<3){$log = "log2";}
	
	$updateQueries = array(
				"
				UPDATE feld
				SET raeuber = 0
				WHERE feld_id = $rPosAlt;",
				"
				UPDATE feld
				SET raeuber = 1
				WHERE feld_id = $rPos;",
				"
				INSERT INTO $log (aktion, pos)
				VALUES (6, $rPos);");
				
	if(isset($_GET['ritter'])){
		$ritter = $_GET['ritter'];
	}else{$ritter=0;}
	
	if($ritter){
		$updateQueries[] = "
				UPDATE spieler
				SET ritter = ritter-1, ritter_auf = ritter_auf + 1
				WHERE spieler_id = $farbe_p";
		
		$rQuery = "
				SELECT ritter_auf
				FROM spieler
				WHERE ritter_auf > 1
				AND ritter_auf = (	SELECT MAX(ritter_auf)
									FROM spieler)
				AND spieler_id = $farbe_p;";
		
		$rRes = mysqli_query($conn,$rQuery);
		if(mysqli_num_rows($rRes)){
			$updateQueries[] = "
			UPDATE etc
			SET rittermacht = $farbe_p;";
			$updateQueries[] = "
			INSERT INTO $log (aktion, farbe, pos)
			VALUES (7, $farbe_p, 1);";
			echo(".2,");
		}else{
			$updateQueries[] = "
			INSERT INTO $log (aktion, farbe)
			VALUES (7, $farbe_p);";
			echo(".1,");
		}
		
	}else{echo(".0,");}
	
	//Give back players with house at robbed field to make available for stealing
	$anliegerQuery = "
				SELECT farbe
				FROM haus
				WHERE f1 = $rPos OR f2 = $rPos OR f3 = $rPos;";
	
	$anliegerRes = mysqli_query($conn, $anliegerQuery);
	$rows = array($farbe_p);

	
	while($row = mysqli_fetch_assoc($anliegerRes)){
		$rowFarbe = $row['farbe'];
		if($rowFarbe>0 && !in_array($rowFarbe, $rows)){
			$rows[] = $rowFarbe;
			echo("$rowFarbe,");
		}
	}
	
	echo(".,");
	
	foreach ($updateQueries as $query) {
		mysqli_query($conn, $query);
	}