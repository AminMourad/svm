<?php
/*
Handles starting phase

Possible outputs
-1 - Invalid input
1 - Field occupied
2 - Street not neighboring house
3 - House too close to other house
4 - Starting phase over, players turn
5 - Error in sequence
6 - Next players turn






*/

	include_once 'sql/sql_connect.php';


	if(isset($_GET['hp']) && isset ($_GET['sp'])){
		$hausid = $_GET['hp'];
		$strasseid = $_GET['sp'];
	}else{exit(".-1,");}

	if(($hausid == 0) || ($strasseid == 0)){
		exit(".-1,");
	}

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


//Getting player number
	$anzahlSpielerRes = mysqli_query($conn,"SELECT spieler_id FROM spieler;");

	$anzahlSpieler = mysqli_num_rows($anzahlSpielerRes);
	


//Getting info about house field for checks
	$hausQuery = "
			SELECT *
			FROM haus
			WHERE haus_id = $hausid;";
				
	$hausRes = mysqli_query($conn, $hausQuery);
	$hausData = mysqli_fetch_assoc($hausRes);


//checking if house field is free
	if($hausData['farbe']!= 0){exit(".1,");}	
	
	
//Setting variables for comparisons
	$h1 = $hausData['h1'];
	$h2 = $hausData['h2'];
	$h3 = $hausData['h3'];
	
	$s1 = $hausData['s1'];
	$s2 = $hausData['s2'];
	$s3 = $hausData['s3'];
	

	
//Checking if street is neighboring house
	if($s1 != $strasseid && $s2 != $strasseid && $s3!= $strasseid) {exit(".2,");}


//Checking if neighboring house plots are empty
	$nachbarQuery = "
			SELECT farbe
			FROM haus
			WHERE haus_id = $h1 OR haus_id = $h2 OR haus_id = $h3;";
	
	$nachbarRes = mysqli_query($conn, $nachbarQuery);

	while($row = mysqli_fetch_assoc($nachbarRes)){
		if($row['farbe'] != 0){
			exit(".3,");
		}
	}
	
	
	
//Checking if street is empty
	$strasseQuery = "
			SELECT farbe
			FROM strasse
			WHERE strasse_id = $strasseid;";
			
	$strasseRes = mysqli_query($conn, $strasseQuery);
	$strasseData = mysqli_fetch_assoc($strasseRes);	

	if($strasseData['farbe'] != 0){exit(".1,");}




//Setting house, street and log
	$log = 'log1';
	if($farbe_p<3){$log = 'log2';}
	
	$feldUpdQuery = array(
			"
			UPDATE strasse 
			SET farbe = $farbe_p 
			WHERE strasse_id = $strasseid;",
			"
            UPDATE haus 
			SET farbe = $farbe_p, typ = 1 
			WHERE haus_id = $hausid;",
			"			
			UPDATE spieler 
			SET siegpunkt = siegpunkt + 1 
			WHERE spieler_id = $farbe_p;",
			"
			INSERT INTO $log (aktion, pos, farbe)
			VALUES (1,$hausid,$farbe_p);",
			"
			INSERT INTO $log (aktion, pos, farbe)
			VALUES (3,$strasseid,$farbe_p);");
			
			
	foreach ($feldUpdQuery as $query) {
		mysqli_query($conn, $query);
	}



//Getting number of points for sequence
	$spQuery = "
			SELECT siegpunkt
			FROM spieler
			WHERE spieler_id = $farbe_p;";
	$spRes = mysqli_query($conn,$spQuery);
	$spArr = mysqli_fetch_assoc($spRes);
	$siegpunkte = $spArr['siegpunkt'];

//Getting position in sequence
	$posQuery = "
			SELECT reihenfolge
			FROM spieler
			WHERE spieler_id = $farbe_p;";
	$posRes =  mysqli_query($conn,$posQuery);
	$posArr = mysqli_fetch_assoc($posRes);
	$reihenfolge = $posArr['reihenfolge'];


//Query what should happen next
	switch($siegpunkte){
		case 1:
			if($reihenfolge < $anzahlSpieler){
				$next = $reihenfolge + 1;
			} else{
				$next = $reihenfolge;
			}
			break;
		case 2:
			if($reihenfolge > 1){
				$next = $reihenfolge - 1;
			}
			break;
		default:
			exit(".5,");
			break;
	}

//Distributing ressources if conditions are met
	if($siegpunkte == 2){
		$resQuery = "
			SELECT feld.ressource
			FROM haus
			LEFT JOIN feld ON haus.f1 = feld.feld_id OR haus.f2 = feld.feld_id OR haus.f3 = feld.feld_id
			WHERE haus.haus_id = $hausid;";
			
		$resRes = mysqli_query($conn, $resQuery);
		
		while($row = mysqli_fetch_assoc($resRes)){
			if($row['ressource']>0){				//Checking if ressource is set
				switch($row['ressource']){			//Assigning ressource to add
					case 1: $ressource = 'holz'; break;
					case 2: $ressource = 'lehm'; break;
					case 3: $ressource = 'erz'; break;
					case 4: $ressource = 'weizen'; break;
					case 5: $ressource = 'schaf'; break;
				}
				
				$updatequery = "
					UPDATE spieler
					SET $ressource = $ressource + 1
					WHERE spieler_id = $farbe_p;";
				
				mysqli_query($conn, $updatequery);
				
				
			}
		}
		if($reihenfolge==1){
			$log = 'log1';		//Other boards turn
			$logZ = 'log2';		//This boards turn
			if($farbe_p<3){
				$log = 'log2';
				$logZ = 'log1';
				}
			
			$logQuery = "						
				INSERT INTO $log (aktion,farbe)
				VALUES(12,$farbe_p);";
			mysqli_query($conn,$logQuery);
			$logQuery = "
				INSERT INTO $logZ (aktion,farbe)
				VALUES(11,$farbe_p);";
			mysqli_query($conn,$logQuery);
			exit(".4,");}
	}
	
	echo(".6,");

//Sets next players turn and terminates
	$nextQuery = "
			SELECT spieler_id
			FROM spieler
			WHERE reihenfolge = $next;";
	$nextRes = mysqli_query($conn,$nextQuery);
	$nextArr = mysqli_fetch_assoc($nextRes);
	$nextSpieler = $nextArr['spieler_id'];

	$zugQuery = "
			UPDATE etc
			SET amzug = $nextSpieler;";
	mysqli_query($conn,$zugQuery);
	
	
	
	$logQueries = array();
	
	switch($nextSpieler){
		case 1:
		case 2:
			$logQueries[] = "
				INSERT INTO log2 (aktion, farbe)
				VALUES (15, $nextSpieler);";
			$logQueries[] = "
				INSERT INTO log1 (aktion, farbe)
				VALUES (14, $nextSpieler);";
			break;
		case 3:
		case 4:
			$logQueries[] = "
				INSERT INTO log2 (aktion, farbe)
				VALUES (14, $nextSpieler);";
			$logQueries[] = "
				INSERT INTO log1 (aktion, farbe)
				VALUES (15, $nextSpieler);";
			break;
	}
	foreach($logQueries as $query){
		mysqli_query($conn,$query);
	}
