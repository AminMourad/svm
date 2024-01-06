<?php
/*
Handels stealing after playing a knight or moving the robber



Oututs:
	0 - invalid input or other error
	1 - Holz stolen
	2 - Lehm stolen
	3 - Erz stolen
	4 - Weizen stolen
	5 - Schaf stolen
	8 -  Player has no ressources
	

*/


	include_once 'sql/sql_connect.php';
	
	if(isset($_GET['fk'])){
		$farbe_k = $_GET['fk'];
		
	}else{exit(".0,");}
	if(isset($_GET['fp'])){
		$farbe_p = $_GET['fp'];
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
			WHERE spieler_id = $farbe_k;";

	$spielerRes = mysqli_query($conn, $spielerQuery);
	$spielerData = mysqli_fetch_assoc($spielerRes);

	$schaf1 = $spielerData['schaf'];
	$lehm1 = $spielerData['lehm'];
	$holz1 = $spielerData['holz'];
	$weizen1 = $spielerData['weizen'];
	$erz1 = $spielerData['erz'];
	
	if($schaf1==0&&$lehm1==0&&$holz1==0&&$weizen1==0&&$erz1==0){
		exit(".7,");
	}

    $asd = array($holz1, $lehm1, $erz1, $weizen1, $schaf1);
    $Ressourcen_k = array();
    $cnt = 0;

    for ($i = 1; $i < 6; $i++){
        while ($asd[$i-1] > 0){
            $Ressourcen_k[$cnt] = $i;
            $cnt += 1;
            $asd[$i-1] -= 1;
        }
    }
    if ($cnt==0){
        exit(".0,");
    }else{       
    $int = rand(0,$cnt-1);
    $x = $Ressourcen_k[$int]; 
}
    echo(".$x,");

	$log = 'log1';
	if($farbe_p<3){$log = 'log2';}
	
	$logQuery = "INSERT INTO $log (aktion, farbe, ressource) VALUES (5,$farbe_k, $x);";
	mysqli_query($conn,$logQuery);
	
	
    switch($x){			
        case 5: 
			$res_upd = "UPDATE spieler SET schaf = schaf-1 WHERE spieler_id = $farbe_k; 
						UPDATE spieler SET schaf = schaf+1 WHERE spieler_id = $farbe_p;";
			mysqli_multi_query($conn, $res_upd);     	
			break;
        case 2: 
			$res_upd = "UPDATE spieler SET lehm = lehm-1 WHERE spieler_id = $farbe_k; 
						UPDATE spieler SET lehm = lehm+1 WHERE spieler_id = $farbe_p;";
			mysqli_multi_query($conn, $res_upd);   
			break;
        case 1: 
			$res_upd = "UPDATE spieler SET holz = holz-1 WHERE spieler_id = $farbe_k;
						UPDATE spieler SET holz = holz+1 WHERE spieler_id = $farbe_p;";
			mysqli_multi_query($conn, $res_upd);     
			break;
        case 4:
			$res_upd = "UPDATE spieler SET weizen = weizen-1 WHERE spieler_id = $farbe_k;
						UPDATE spieler SET weizen = weizen+1 WHERE spieler_id = $farbe_p;";
			mysqli_multi_query($conn, $res_upd);    
			break;
        case 3:
			$res_upd = "UPDATE spieler SET erz = erz-1 WHERE spieler_id = $farbe_k;
						UPDATE spieler SET erz = erz+1 WHERE spieler_id = $farbe_p;";
			mysqli_multi_query($conn, $res_upd);    
			break;
    }

?>