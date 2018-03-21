<!DOCTYPE html>
<html lang="ru">
<head>
	<meta charset="UTF-8">
	<title>Document</title>
</head>
<body>
	<?php
$hostName = "localhost";
$userName = "root";
$userPassword = "";

$connectionID = mysql_connect($hostName,$userName,$userPassword) OR DIE ('ERROR');

$dbName = 'firm_info_db';
mysql_select_db($dbName);

$tableName = 'placement_temp2';


if ($_POST['add']){
	echo "WILL BE ADD: ".$_POST['firm_id_field']." ".$_POST['adress_field']." ".$_POST['square_field']." ".$_POST['type_placement'];

	$sqlQuare = "INSERT INTO $tableName VALUES('".$_POST['adress_field']."','".$_POST['firm_id_field']."','".$_POST['square_field']."','".$_POST['type_placement']."')";
	
	$sqlResult = mysql_query($sqlQuare) OR DIE (mysql_error());
};	

if ($_POST['rewrite']){
	echo "WILL BE REWITE: ".$_POST['firm_id_field']." ".$_POST['adress_field']." ".$_POST['square_field']." ".$_POST['type_plcement'];

	$sqlQuare = "UPDATE $tableName SET adress='".$_POST['adress_field']."',square='".$_POST['square_field']."',type_placement='".$_POST['type_placement']."' WHERE firm_id='".$_POST['firm_id_field']."'";

	$sqlResult = mysql_query($sqlQuare) OR DIE (mysql_error());
}

if ($_POST['delete']){
	echo "WILL BE DELETE: ".$_POST['firm_id_field']." ".$_POST['adress_field']." ".$_POST['square_field']." ".$_POST['type_placement'];

	$sqlQuare = "DELETE FROM $tableName WHERE firm_id='".$_POST['firm_id_field']."'";

	$sqlResult = mysql_query($sqlQuare) OR DIE (mysql_error());
};


mysql_close();


?>

</body>
</html>
