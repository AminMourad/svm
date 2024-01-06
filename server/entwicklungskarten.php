<?php


/*

Error codes:
0 - Not enough Ressources


Available Cards:
1.Knight 	  (19)
2.Development (3)
3.Streets	  (3)
4.Monopoly    (2)
5.Point	      (5)

*/


	include_once 'sql/sql_connect.php';

	//Getting player info

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


	$spielerQuery = "
				SELECT *
				FROM spieler
				WHERE spieler_id = $farbe_p;";

			$spielerRes = mysqli_query($conn, $spielerQuery);
			$spielerData = mysqli_fetch_assoc($spielerRes);

	if($spielerData['schaf'] < 1  || $spielerData['erz'] < 1 || $spielerData['weizen'] < 1){
			exit(".0,");
		}

	// Update players ressources

	$res_update = "UPDATE spieler SET schaf = schaf-1, erz = erz-1, weizen = weizen-1 WHERE spieler_id = $farbe_p;";
	mysqli_query($conn, $res_update);


	//Array for development cards (a bought card doesn't change the probability, so every draw is distributed, like the first one in a normal game would. Could be changed to a more realistic system where cards are removed from the stack when drawing them by incorporating the database)
	$Ereigniskarten = array(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,3,3,3,4,4,5,5,5,5,5);

	$int = rand(0,31);
	$x = $Ereigniskarten[$int];
	
	
	//Add development card to players inentory (streets can be played by just building a street, no ressurcces will be deducted if inventory contains streets)

	switch($x){			
		case 1: $x = 1; $res_upd = "UPDATE spieler SET ritter = ritter+1 WHERE spieler_id = $farbe_p;"; mysqli_multi_query($conn, $res_upd);     		break;
		case 2: $x = 2; $res_upd = "UPDATE spieler SET erfindung = erfindung+1 WHERE spieler_id = $farbe_p;"; mysqli_multi_query($conn, $res_upd);      break;
		case 3: $x = 3; $res_upd = "UPDATE spieler SET strasse = strasse+2 WHERE spieler_id = $farbe_p;"; mysqli_multi_query($conn, $res_upd);     		break;
		case 4: $x = 4; $res_upd = "UPDATE spieler SET monopol = monopol+1 WHERE spieler_id = $farbe_p;"; mysqli_multi_query($conn, $res_upd);     		break;
		case 5: $x = 5; $res_upd = "UPDATE spieler SET siegpunkt = siegpunkt+1 WHERE spieler_id = $farbe_p;"; mysqli_multi_query($conn, $res_upd);      break;
		}
	
	echo ".$x,";
