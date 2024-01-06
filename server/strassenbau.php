<?php
/*
Handles building streets and the necessary checks for validity

Output:
   -1 - Invalid input
    1 - no neighbouring street
	2 - Not enough ressources
	5 - No streets left
	6 - Street built


*/

    include_once 'sql/sql_connect.php';



	if(isset($_GET['sp'])){
	$strasseid = $_GET['sp'];
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

	$strasseQuery = "
			SELECT *
			FROM strasse
			WHERE strasse_id = $strasseid;";
			
	$strasseRes = mysqli_query($conn,$strasseQuery);
	$strasseData = mysqli_fetch_assoc($strasseRes);


	//Check if field is empty

	if($strasseData['farbe']!= 0){exit(".0,");}
	
	//Check if player has a neighbouring street

	$sk1 = $strasseData['sk1'];
	$sk2 = $strasseData['sk2'];
	$sk3 = $strasseData['sk3'];
	$sk4 = $strasseData['sk4'];

	$sNachbarQuery = "
			SELECT farbe
			FROM strasse
			WHERE strasse_id = $sk1 OR strasse_id = $sk2 OR strasse_id = $sk3 OR strasse_id = $sk4;";
	
	$sNachbarRes = mysqli_query($conn, $sNachbarQuery);
	
	$strassePasst = false;
	
	while($row = mysqli_fetch_assoc($sNachbarRes)){
		if($row['farbe'] == $farbe_p){
			$strassePasst = true;
		}
	}

	if($strassePasst == false){exit(".1,");}
		
	//Check if player has streets left to build
	$anzahlQuery = "
				SELECT strasse_id
				FROM haus
				WHERE farbe = $farbe_p AND typ = 1;";
	$anzahlRes = mysqli_query($conn, $anzahlQuery);
	$anzahlResRows = mysqli_num_rows($anzahlRes);
	if($anzahlResRows > 14){
		exit(".5,");

	}
		
	//Check if player has enough ressources or street from development card
		
	$spielerQuery = "
			SELECT *
			FROM spieler
			WHERE spieler_id = $farbe_p;";

		$spielerRes = mysqli_query($conn, $spielerQuery);
		$spielerData = mysqli_fetch_assoc($spielerRes);

		$lehm1 = $spielerData['lehm'];
		$holz1 = $spielerData['holz'];
		
	if($spielerData['strasse']>0){
		$spielerUpdate = "strasse = strasse -1";
	}elseif($spielerData['lehm'] < 1 || $spielerData['holz'] < 1 ){
		exit(".2,");
	}else{
		$spielerUpdate = "lehm = lehm-1, holz = holz-1";
	}
	
	
	
	
	//Update db tables and log
	$log = "log1";
	if($farbe_p<3){$log = "log2";}
	
	$res_upd = "
			UPDATE spieler 
			SET $spielerUpdate  
			WHERE spieler_id = $farbe_p;
			
			UPDATE strasse 
			SET farbe = $farbe_p 
			WHERE strasse_id = $strasseid;
			
			INSERT INTO $log (aktion, pos, farbe)
			VALUES (3, $strasseid, $farbe_p);";
			
	mysqli_multi_query($conn, $res_upd);
	
	
	
	echo ".6,";	
	
	
	
	
	
	

	


?>