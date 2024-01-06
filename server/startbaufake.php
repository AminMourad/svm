<?php
/*
A fake start building script, that was used during a presentation in which the sensors didn't work yet. It always gives back a preset valid starting pattern, even if no valid input is given on where the house and street are. Comments not translated as this isn't intended for use.

0 - Ungültige Eingabe
1 - Feld besetzt
2 - Strasse nicht an Haus anliegend
3 - Haus zu nah an Gegnern
4 - Startphase um. Spieler am Zug
5 - Fehler in der Zugfolge
6 - Nächster Spieler am Zug






*/

	include_once 'sql/sql_connect.php';

	$a=1;
	$gehtnisch = 0;
	
	if(isset($_GET['hp']) && isset ($_GET['sp'])){
		$hausid = $_GET['hp'];
		$strasseid = $_GET['sp'];
	}else{$a=0;$gehtnisch=1;}

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
		
	//Ermitteln der anzahl der siegpunkte (braucht man für die Reihenfolge)
	$spQuery = "
			SELECT siegpunkt
			FROM spieler
			WHERE spieler_id = $farbe_p;";
	$spRes = mysqli_query($conn,$spQuery);
	$spArr = mysqli_fetch_assoc($spRes);
	$siegpunkte = $spArr['siegpunkt'];


//Spieleranzahl ermitteln

	$anzahlSpielerRes = mysqli_query($conn,"SELECT spieler_id FROM spieler;");

	$anzahlSpieler = mysqli_num_rows($anzahlSpielerRes);
	


//überprüfen von Spielzug gültigkeit
	
	while($a){
	
	$hausQuery = "
			SELECT *
			FROM haus
			WHERE haus_id = $hausid;";
				
	$hausRes = mysqli_query($conn, $hausQuery);
	$hausData = mysqli_fetch_assoc($hausRes);


//Hausfeld frei?
	if($hausData['farbe']!= 0){
		$gehtnisch=1;
		break;
		}
	
	

	$h1 = $hausData['h1'];
	$h2 = $hausData['h2'];
	$h3 = $hausData['h3'];
	
	$s1 = $hausData['s1'];
	$s2 = $hausData['s2'];
	$s3 = $hausData['s3'];
	

	
//Ist die gesetzte Strasse am Haus
	if($s1 != $strasseid && $s2 != $strasseid && $s3!= $strasseid) {
		$gehtnisch=1;
		break;}

//Sind benachbarte Häuserfelder frei
	$nachbarQuery = "
			SELECT farbe
			FROM haus
			WHERE haus_id = $h1 OR haus_id = $h2 OR haus_id = $h3;";
	
	$nachbarRes = mysqli_query($conn, $nachbarQuery);

	while($row = mysqli_fetch_assoc($nachbarRes)){
		if($row['farbe'] != 0){
			$gehtnisch=1;
			break;
		}
	}
	
	
	
//Strassenfeld frei?
	$strasseQuery = "
			SELECT farbe
			FROM strasse
			WHERE strasse_id = $strasseid;";
			
	$strasseRes = mysqli_query($conn, $strasseQuery);
	$strasseData = mysqli_fetch_assoc($strasseRes);	

	if($strasseData['farbe'] != 0){
		$gehtnisch=1;
		break;}
		
	break;
	}

	if($gehtnisch){
		$positionen = array(29,5,28,27,103,98,102,100,19,56,54,55,80,41,81,83);
		$farbe = $farbe_p-1;
		$strasseid = $positionen[$farbe*4+$siegpunkte+2];
		$hausid = $positionen[$farbe*4+$siegpunkte];
	}

//setzt haus und strasse und log
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
	
	$siegpunkte++;
	


//Ermitteln der Position in der Reihenfolge
	$posQuery = "
			SELECT reihenfolge
			FROM spieler
			WHERE spieler_id = $farbe_p;";
	$posRes =  mysqli_query($conn,$posQuery);
	$posArr = mysqli_fetch_assoc($posRes);
	$reihenfolge = $posArr['reihenfolge'];

//Abfrage, was als nächstes passieren soll

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

//Verteile ggf. Ressourcen	
	if($siegpunkte == 2){
		$resQuery = "
			SELECT feld.ressource
			FROM haus
			LEFT JOIN feld ON haus.f1 = feld.feld_id OR haus.f2 = feld.feld_id OR haus.f3 = feld.feld_id
			WHERE haus.haus_id = $hausid;";
			
		$resRes = mysqli_query($conn, $resQuery);
		
		while($row = mysqli_fetch_assoc($resRes)){
			if($row['ressource']>0){				//Überprüfung ob gültiger Eintrag mit gesetzter Ressource, sonst nächster Eintrag
				switch($row['ressource']){			//Zuweisung der Ressourcen von Zahlen auf DB-Felder
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
				
				mysqli_query($conn, $updatequery);		//Ausführung des Update-Befehls
				
				
			}
		}
		if($reihenfolge==1){
			$log = 'log1';		//Brett nicht am Zug
			$logZ = 'log2';		//Brett am Zug
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
	
//Setze nächsten Spieler an den Zug und beende
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
	echo(".6,");


