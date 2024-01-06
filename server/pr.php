<?php
//alternative implementation of the fake start building

	include_once 'sql/sql_connect.php';


	$farbeQuery = "
			SELECT amzug
			FROM etc;";
	$farbeRes = mysqli_query($conn, $farbeQuery);
	$farbeArr = mysqli_fetch_assoc($farbeRes);
	$farbe_p  = $farbeArr['amzug'];
	
	
	$spQuery = "
			SELECT siegpunkt
			FROM spieler
			WHERE spieler_id = $farbe_p;";
	$spRes = mysqli_query($conn,$spQuery);
	$spArr = mysqli_fetch_assoc($spRes);
	$siegpunkte = $spArr['siegpunkt'];
	if($siegpunkte>1){exit("startphase schon um");}
	
	$positionen = array(29,5,28,27,103,98,102,100,19,56,54,55,80,41,81,83);
	
	$farbe = $farbe_p-1;
	$sp = $positionen[$farbe*4+$siegpunkte+2];
	$hp = $positionen[$farbe*4+$siegpunkte];
	
		
		
	header("Location: http://mourad.pw/svm/startbau.php?hp=$hp&sp=$sp");