<?php

/*
handels playing the monopoly development card

error log:
    0 --> invalid input
    5 --> no ressources gotten
*/

include_once 'sql/sql_connect.php';

if(isset($_GET['r'])){
	$ressource_k = $_GET['r'];
	
}else{exit(".0,");}

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



switch($ressource_k){
    case 1: $ressource = 'holz';   break;
    case 2: $ressource = 'lehm';   break;
    case 3: $ressource = 'erz';    break;
    case 4: $ressource = 'weizen'; break;
    case 5: $ressource = 'schaf';  break;
}

        $total_query = "SELECT sum($ressource) AS summe FROM spieler;";
        $totalRes = mysqli_query($conn, $total_query);
        $totalData = mysqli_fetch_assoc($totalRes);                      
        $log = 'log1';

	    if($farbe_p<3){$log = 'log2';}

        $x = $totalData['summe'];

        if ($x == 0){exit(".5,");}

        $res_upd = "UPDATE spieler SET $ressource = 0; 
                    UPDATE spieler SET $ressource = $x WHERE spieler_id = $farbe_p;
					UPDATE spieler SET monopol = monopol-1 WHERE spieler_id = $farbe_p;
                    
                    INSERT INTO $log (aktion, res, farbe)
                    VALUES (7, $ressource_k, $farbe_p);";
        mysqli_multi_query($conn, $res_upd);

        

    echo (".6,");
?>