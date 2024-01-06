<?php

/*
Handles manual trade


operator:    0 --> deduct
             1 --> add

ressource:   1 --> holz
             2 --> lehm
             3 --> erz
             4 --> weizen
             5 --> schaf

Output:     -1 --> Invalid input
			 0 --> Not enough to deduct
             1 --> Worked
             
*/

include_once 'sql/sql_connect.php';

if(isset($_GET['r']) && isset ($_GET['f']) && isset ($_GET['o'])){
	$ressource = $_GET['r'];
	$farbe_p = $_GET['f'];
	$operator = $_GET['o'];

}else{exit(".-1,");}

$spielerQuery = "SELECT *
			    FROM spieler
			    WHERE spieler_id = $farbe_p;";

		$spielerRes = mysqli_query($conn, $spielerQuery);
		$spielerData = mysqli_fetch_assoc($spielerRes);


if ($operator == 0){
    if($ressource == 1){
        if($spielerData['holz'] < 1){
            exit(".0,");
        }
        $res_upd = "UPDATE spieler SET holz = holz-1 WHERE spieler_id = $farbe_p;";
    }
    if($ressource == 2){
        if($spielerData['lehm'] < 1){
            exit(".0,");
        }
        $res_upd = "UPDATE spieler SET lehm = lehm-1 WHERE spieler_id = $farbe_p;";
    }
    if($ressource == 3){
        if($spielerData['erz'] < 1){
            exit(".0,");
        }
        $res_upd = "UPDATE spieler SET erz = erz-1 WHERE spieler_id = $farbe_p;";
    }
    if($ressource == 4){
        if($spielerData['weizen'] < 1){
            exit(".0,");
        }
        $res_upd = "UPDATE spieler SET weizen = weizen-1 WHERE spieler_id = $farbe_p;";
    }
    if($ressource == 5){
        if($spielerData['schaf'] < 1){
            exit(".0,");
        }
         $res_upd = "UPDATE spieler SET schaf = schaf-1 WHERE spieler_id = $farbe_p;";
    }
}

if ($operator == 1){
    if($ressource == 1){
        $res_upd = "UPDATE spieler SET holz = holz+1 WHERE spieler_id = $farbe_p;";
    }
    if($ressource == 2){
        $res_upd = "UPDATE spieler SET lehm = lehm+1 WHERE spieler_id = $farbe_p;";
    }
    if($ressource == 3){
        $res_upd = "UPDATE spieler SET erz = erz+1 WHERE spieler_id = $farbe_p;";
    }
    if($ressource == 4){
        $res_upd = "UPDATE spieler SET weizen = weizen+1 WHERE spieler_id = $farbe_p;";
    }
    if($ressource == 5){
         $res_upd = "UPDATE spieler SET schaf = schaf+1 WHERE spieler_id = $farbe_p;";
    }
}
mysqli_query($conn,$res_upd);

echo ".1,";
?>