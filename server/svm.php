<?php

	if(isset($_GET['test'])){
		echo "test \r\n";
		$test = $_GET['test'];
		$test3 = $test*3;
		echo "Deine Zahl mal drei: {$test3}.\r\n";
	}

	if(isset($_GET['test2'])){
		echo "test2\r\n";
		$test2 = $_GET['test2'];
		$test2x = $test2*5/2;
		echo "Deine zweite Zahl mal fünf durch 2: {$test2x}.\r\n";
	}
	
	echo 'immertest!';
	
	exit;
?>