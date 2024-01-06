<?php
/*
Handles building cities and the necessary checks for validity

Output:
   -1 - Invalid input
	2 - Not enough ressources
	4 - No existing house to build city
	5 - Not enough cities left
	6 - City built


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
	
//Checking if player has a house where they want to build a city

    $stadtQuery = "
			SELECT *
			FROM haus
			WHERE haus_id = $hausid;";

    $stadtRes = mysqli_query($conn, $stadtQuery);
    $stadtData = mysqli_fetch_assoc($stadtRes);

    if($stadtData['farbe']!= $farbe_p || $stadtData['typ']!= 1){
        exit(".4,");
    }
    
//Checking if player has enough ressources

    $spielerQuery = "
			SELECT *
            FROM spieler
            WHERE spieler_id = $farbe_p;";

    $spielerRes = mysqli_query($conn, $spielerQuery);
    $spielerData = mysqli_fetch_assoc($spielerRes);

    if($spielerData['weizen'] < 2 || $spielerData['erz'] < 3){
    exit(".2,");
    }

//Checking if player has cities left to build

$anzahlQuery = "
			SELECT haus_id
			FROM haus
			WHERE farbe = $farbe_p AND typ = 2;";  //typ 1 bei Hausbau, 2 bei Stadtbau
$anzahlRes = mysqli_query($conn, $anzahlQuery);
$anzahlResRows = mysqli_num_rows($anzahlRes);
if($anzahlResRows > 3){
	exit(".5,");
}

//Updating players ressources, house table and log
	$log = 'log1';
	if($farbe_p<3){$log = 'log2';}
	
    $res_upd = "
			UPDATE spieler 
			SET weizen = weizen-2, erz = erz-3, siegpunkt = siegpunkt + 1 
			WHERE spieler_id = $farbe_p;
			
			UPDATE haus 
			SET typ = 2 
			WHERE haus_id = $hausid;
			
			INSERT INTO $log (aktion, pos, farbe)
			VALUES (2, $hausid, $farbe_p);";
	mysqli_multi_query($conn, $res_upd);

echo ".6,";
?>