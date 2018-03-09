<!DOCTYPE html>
<html lang="ru">
<head>
	<meta http-equiv="Contetnt-Type" content="text/html">
	<meta charset="UTF-8">
	<meta name="author" content="Generalov_Nikolay_Nikolaevich">
	<meta name="ROBOTS" content="ALL">
	<meta name="Keywords" content="лабораторная работа, MySQL, соединение с БД">
	<meta name="Description" CONTENT="Лабораторная работа '1. Соединение с базой данных'">

	<title>Лабораторная работа '1. Соединение с базой данных'</title>
</head>
<body>
	<?	

	$hostName = "localhost";
	$userName = "student";
	$userPassword = "student";

	$dataBasename = "lab1";
	$tableName = "Phonelib";

	$linkID = mysql_connect($hostName, $userName, $userPassword) or die("ERROR, NOT LOGINED");

	mysql_select_db($dataBasename) or die("ERROR, DB NOT OPEN!");
	$query = "SELECT * FROM $tableName";

	$result = mysql_query($query) or die("ERROR, QUERY NOT USED");

	echo "Результат выборки из БД: \n";
	echo "
	<table border='1'>
	
		<tr>
			<th>ID</th>
			<th>FIO</th>
			<th>B_DATE</th>
		</tr>
	";

	while ($row = mysql_fetch_array($result)){

		echo "

		<tr>
			<td>".$row['ID']."</td>
			<td>".$row['FIO']."</td>
			<td>".$row['bdate']."</td>
		</tr>
		";
	}

	echo "</table>";

	mysql_close($linkID);
	?>
	
</body>
</html>