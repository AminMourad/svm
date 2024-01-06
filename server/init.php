<?php
/*
Handels the initialiation of the game
Comments lacking

*/


	include_once 'sql/sql_connect.php'; 
	include_once 'zahlverteilung.php';
	include_once 'resverteilung.php';
	
	//Getting input variables
	if(isset($_GET['b']) && $_GET['spieler']){
		$b = $_GET['b'];
		$spieler = $_GET['spieler'];
	}else{exit("..,");};
	if(isset($_GET['s'])){
		$standard = $_GET['s'];
	}else{$standard = 0;};
	
	$readyQuery = "
			SELECT ready
			FROM etc;";
	$amZugQuery = "
			UPDATE etc
			SET amzug = 0;";
	$readyRes = mysqli_query($conn, $readyQuery);
	$readyArr = mysqli_fetch_assoc($readyRes);
	$readystate = $readyArr['ready'];
	
	mysqli_query($conn,$amZugQuery);
	
	if($readystate==0 || ($readystate>0 && $b==1) || ($readystate<0 && $b==2)){
		
		echo(".2,");
		
		if($b==2){
		$spieler = -1 * $spieler;}
		
		$readyUpdateQueries = array(
			"
			UPDATE etc
			SET ready = $spieler, rittermacht=0;",
			"
			UPDATE feld
			SET ressource = 0, zahl = 0, raeuber = 0
			WHERE NOT feld_id=19;",
			"
			UPDATE feld
			SET raeuber = 1
			WHERE feld_id = 19;",
			"
			TRUNCATE TABLE log1;",
			"
			TRUNCATE TABLE log2;");
			
		foreach ($readyUpdateQueries as $query) {
		mysqli_query($conn, $query);
		}
		
		$zahlstart = zahlverteilung($standard);
		resverteilung($standard);
		
		$felderQuery = "
			SELECT ressource
			FROM feld;";
			
		$felderRes = mysqli_query($conn,$felderQuery);
		
		while($row = mysqli_fetch_assoc($felderRes)){
			echo implode(",",$row) . ",";
		}
		echo("$zahlstart,");
		exit(".,");
	}
	
	$readystate = abs($readystate);
	
	$mitspieler = array();
	
	//switch statement to fill array spieler with the correct playing players
	switch($b){
		case 1:
			switch($spieler){
				case 1:
					$mitspieler[]=1;
					break;
				case 2:
					$mitspieler[]=2;
					break;
				case 3:
					$mitspieler[]=1;
					$mitspieler[]=2;
					break;
			}
			switch($readystate){
				case 1:
					$mitspieler[]=3;
					break;
				case 2:
					$mitspieler[]=4;
					break;
				case 3:
					$mitspieler[]=3;
					$mitspieler[]=4;
					break;
			}
			break;
		case 2:
			switch($readystate){
				case 1:
					$mitspieler[]=1;
					break;
				case 2:
					$mitspieler[]=2;
					break;
				case 3:
					$mitspieler[]=1;
					$mitspieler[]=2;
					break;
			}
			switch($spieler){
				case 1:
					$mitspieler[]=3;
					break;
				case 2:
					$mitspieler[]=4;
					break;
				case 3:
					$mitspieler[]=3;
					$mitspieler[]=4;
					break;
			}
			break;
	}
	
	$resetQueries = array(
			"
			UPDATE strasse
			SET farbe = 0;",
			"
			UPDATE haus
			SET farbe = 0, typ = 0;",
			"
			TRUNCATE TABLE spieler;",
			"
			UPDATE etc
			SET ready = 0;");
			
	foreach ($resetQueries as $query) {
		mysqli_query($conn, $query);
	}

	
	$spielerAnzahl = count($mitspieler);
	$reihenfolge = array(); 
	$reihenfolge[] = 0;
	$erster = random_int(0, $spielerAnzahl-1);
	$reihenfolge[] = $mitspieler[$erster];
	$startSpieler = $reihenfolge[1];
	
	//semi-random sequence generation, keeping both players of a board after each other
	switch($startSpieler){
		case 1:
			if(in_array('2',$mitspieler)){$reihenfolge[]=2;}
			$z = random_int(3,4);
			if($z==3){
				if(in_array('3',$mitspieler)){$reihenfolge[]=3;}
				if(in_array('4',$mitspieler)){$reihenfolge[]=4;}
			}
			if($z==4){
				if(in_array('4',$mitspieler)){$reihenfolge[]=4;}
				if(in_array('3',$mitspieler)){$reihenfolge[]=3;}
			}
			break;
		case 2:
			if(in_array('1',$mitspieler)){$reihenfolge[]=1;}
			$z = random_int(3,4);
			if($z==3){
				if(in_array('3',$mitspieler)){$reihenfolge[]=3;}
				if(in_array('4',$mitspieler)){$reihenfolge[]=4;}
			}
			if($z==4){
				if(in_array('4',$mitspieler)){$reihenfolge[]=4;}
				if(in_array('3',$mitspieler)){$reihenfolge[]=3;}
			}
			break;
		case 3:
			if(in_array('4',$mitspieler)){$reihenfolge[]=4;}
			$z = random_int(1,2);
			if($z==1){
				if(in_array('1',$mitspieler)){$reihenfolge[]=1;}
				if(in_array('2',$mitspieler)){$reihenfolge[]=2;}
			}
			if($z==2){
				if(in_array('2',$mitspieler)){$reihenfolge[]=2;}
				if(in_array('1',$mitspieler)){$reihenfolge[]=1;}
			}
			break;
		case 4:
			if(in_array('3',$mitspieler)){$reihenfolge[]=3;}
			$z = random_int(1,2);
			if($z==1){
				if(in_array('1',$mitspieler)){$reihenfolge[]=1;}
				if(in_array('2',$mitspieler)){$reihenfolge[]=2;}
			}
			if($z==2){
				if(in_array('2',$mitspieler)){$reihenfolge[]=2;}
				if(in_array('1',$mitspieler)){$reihenfolge[]=1;}
			}
			break;
	}


	$flippedReihenfolge = array_flip($reihenfolge);
	
	//Creation of players
	for($i=0; $i<$spielerAnzahl; $i++){
		$spieler_id = $mitspieler[$i];
		$reihe = $flippedReihenfolge[$spieler_id];
		$spielerQuery="
			INSERT INTO spieler (spieler_id, reihenfolge)
			VALUES ($spieler_id, $reihe);";
		mysqli_query($conn,$spielerQuery);
	}
	
	$felderQuery = "
		SELECT ressource
		FROM feld;";
		
	$felderRes = mysqli_query($conn,$felderQuery);
	echo(".1,");
	while($row = mysqli_fetch_assoc($felderRes)){
		echo implode(",",$row) . ",";
	}
	
	$startzahlQuery="
		SELECT feld_id
		FROM feld
		WHERE zahl=5 AND feld_id<13;";
		
	$startzahlRes = mysqli_query($conn,$startzahlQuery);
	$startzahlArr = mysqli_fetch_assoc($startzahlRes);
	$startzahl = $startzahlArr['feld_id'];
	
	echo("$startzahl,");
	
	$log="log1";
	if($b==1){
		$log="log2";
	}
	
	$spielerQueries = array(
		"
		UPDATE etc
		SET amzug = $startSpieler;",
		"
		INSERT INTO $log (aktion)
		VALUES(13);");

	
	switch($startSpieler){
		case 1:
		case 2:
			$spielerQueries[] = "
				INSERT INTO log2 (aktion, farbe)
				VALUES (15,$startSpieler);";
			$spielerQueries[] = "
				INSERT INTO log1 (aktion, farbe)
				VALUES (14,$startSpieler);";
			break;
		case 3:
		case 4:
			$spielerQueries[] = "
				INSERT INTO log2 (aktion, farbe)
				VALUES (14,$startSpieler);";
			$spielerQueries[] = "
				INSERT INTO log1 (aktion, farbe)
				VALUES (15,$startSpieler);";
			break;
				
		
	}
	
	foreach($spielerQueries as $query){
		mysqli_query($conn,$query);
	}
	
	exit(".,");
	

