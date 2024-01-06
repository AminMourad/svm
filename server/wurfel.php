<?php
//handels dice roll and consequent ressource distrivution


	include_once 'sql/sql_connect.php'; 		
	
	
	
	$e = random_int(1,6) + random_int(1,6); 	//generate dice roll
	
	
	//give back 7 immedietly as there is no ressource distribution when rolling 7. Moving robber is handled by different routine
	if($e==7){exit(".7,");}	

	
	//read all settlements and adjacent to the rolled numbers ressources
	$fetchQuery = "
		SELECT haus.farbe, haus.typ, feld.ressource
		FROM haus
		LEFT JOIN feld ON haus.f1 = feld.feld_id OR haus.f2 = feld.feld_id OR haus.f3 = feld.feld_id
		WHERE feld.zahl=$e AND feld.raeuber = 0;";
	
	
	$res = mysqli_query($conn, $fetchQuery);

	$resRows = mysqli_num_rows($res);
	if($resRows == 0){exit("$e");}				//exit if there arent't settlements next to the rolled numbers fields
	
	
	while($row = mysqli_fetch_assoc($res)){
		if($row['ressource']>0){				//checking if valid entry, otherwise move on
			switch($row['ressource']){			//set ressource according to db entry
				case 1: $ressource = 'holz'; break;
				case 2: $ressource = 'lehm'; break;
				case 3: $ressource = 'erz'; break;
				case 4: $ressource = 'weizen'; break;
				case 5: $ressource = 'schaf'; break;
			}
			$typ = $row['typ'];
			$spieler = $row['farbe'];			//saving type (settlement or city) and according player in variable
			//increment players ressource by one or two according to type
			$updateQuery = "
				UPDATE spieler
				SET $ressource = $ressource + $typ
				WHERE spieler_id=$spieler;";
			
			mysqli_query($conn, $updateQuery);
		}
	}		
	
	//give back dice roll
	echo ".$e,";
	
	//write dice roll into correct logs
	if(isset($_GET['b'])){
		switch($_GET['b']){
			case 1:
				$log = 'log2';
				break;
			case 2:
				$log = 'log1';
				break;
		}
	}else{
		$farbeQuery = "
				SELECT amzug
				FROM etc;";
		$farbeRes = mysqli_query($conn, $farbeQuery);
		$farbeArr = mysqli_fetch_assoc($farbeRes);
		switch($farbeArr['amzug']){
			case 1:
			case 2:
				$log = 'log2';
				break;
			case 3:
			case 4:
				$log = 'log1';
				break;
		}
	}
	
	$logQuery = "
		INSERT INTO $log (aktion, augenzahl)
		VALUES (4,$e);";
	mysqli_query($conn, $logQuery);