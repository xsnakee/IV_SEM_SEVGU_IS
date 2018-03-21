<?php
$hostName = "localhost";
$userName = "root";
$userPassword = "";

$connectionID = mysql_connect($hostName,$userName,$userPassword) OR DIE ('ERROR');

$dbName = 'firm_info_db';

mysql_select_db($dbName);

$tableName = 'placement_temp2';

$queryresult = mysql_query("SELECT * FROM $tableName");

ECHO "<table class='SQL_SELECT_TABLE'>";
ECHO "<tr><th>ID фирмы</th><th>Адрес</th><th>Площадь</th><th>Тип площади</th></tr>";

while ($row = mysql_fetch_array($queryresult)){
ECHO "
<tr><td>".$row['firm_id']."</td><td>".$row['adress']."</td><td>".$row['square']."</td><td>".$row['type_placement']."</td></tr>";
}

ECHO "</table>";

mysql_close();


?>