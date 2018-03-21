<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<link rel="stylesheet" href="css/style.css">
	<title>SQL labs</title>
</head>
<body>

<?php 
include 'viewDB.php'
 ?>


<form id="send_form" method="post" action="editDB.php">
	<input type="text" name='adress_field' placeholder="Enter adress">
	<input type="text" name='firm_id_field' placeholder="Enter firm_id">
	<input type="text" name='square_field' placeholder="Enter square">
	<select name="type_placement_field">
		<option value="1">1</option>
		<option value="2">2</option>
		<option value="3">3</option>
		<option value="4">4</option>
		<option value="5">5</option>
	</select>
	<input type="submit" name="add" value="add" >
	<input type="submit" name="rewrite" value="rewrite" >
	<input type="submit" name="delete" value="delete" >
</form> 



</body>
</html>