<?php
/*
Handles building houses and the necessary checks for validity

Output:
   -1 - Invalid input
	0 - Field occupied
	1 - No neighbouring street
	2 - Not enough ressources
	3 - Too close to existing house
	5 - Not enough houses left



*/



	include_once 'sql/sql_connect.php';

	

	if(isset($_GET['hp'])){
		$hausid = $_GET['hp'];
	}else{exit(".-1,");}
	
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


//Check if field is empty
	$hausQuery = "
			SELECT *
			FROM haus
			WHERE haus_id = $hausid;";
			
	$hausRes = mysqli_query($conn, $hausQuery);
	$hausData = mysqli_fetch_assoc($hausRes);
	
	if($hausData['farbe']!= 0){exit(".0,");}
	
	$h1 = $hausData['h1'];
	$h2 = $hausData['h2'];
	$h3 = $hausData['h3'];
	
	
//Check if neighbouring house fields are empty
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

//Check if player has neighbouring street
	$s1 = $hausData['s1'];
	$s2 = $hausData['s2'];
	$s3 = $hausData['s3'];
	
	$sNachbarQuery = "
			SELECT farbe
			FROM strasse
			WHERE strasse_id = $s1 OR strasse_id = $s2 OR strasse_id = $s3;";
	
	$sNachbarRes = mysqli_query($conn, $sNachbarQuery);
	
	$strassePasst = false;
	
	while($row = mysqli_fetch_assoc($sNachbarRes)){
		if($row['farbe'] == $farbe_p){
			$strassePasst = true;
		}
		
	}

	if($strassePasst == false){exit(".1,");}

//Check if player has enough ressources



	$spielerQuery = "
			SELECT *
			FROM spieler
			WHERE spieler_id = $farbe_p;";

		$spielerRes = mysqli_query($conn, $spielerQuery);
		$spielerData = mysqli_fetch_assoc($spielerRes);

		$schaf1 = $spielerData['schaf'];
		$lehm1 = $spielerData['lehm'];
		$holz1 = $spielerData['holz'];
		$weizen1 = $spielerData['weizen'];

	if($spielerData['schaf'] < 1 || $spielerData['lehm'] < 1 || $spielerData['holz'] < 1 || $spielerData['weizen'] < 1){
		exit(".2,");
	}

//Check if player has houses left to build
$anzahlQuery = "
			SELECT haus_id
			FROM haus
			WHERE farbe = $farbe_p AND typ = 1;";
$anzahlRes = mysqli_query($conn, $anzahlQuery);
$anzahlResRows = mysqli_num_rows($anzahlRes);
if($anzahlResRows > 4){
	exit(".5,");

}


//Update db tables and log
	$log = 'log1';
	if($farbe_p<3){$log = 'log2';}

	$res_upd = "
			UPDATE spieler 
			SET schaf = schaf-1, lehm = lehm-1, holz = holz-1, weizen = weizen-1, siegpunkt = siegpunkt + 1 
			WHERE spieler_id = $farbe_p;
			
			UPDATE haus 
			SET farbe = $farbe_p, typ = 1 
			WHERE haus_id = $hausid;
			
			INSERT INTO $log (aktion, pos, farbe)
			VALUES (1, $hausid, $farbe_p);";
	mysqli_multi_query($conn, $res_upd);

		
	
echo ".6,";
?>
