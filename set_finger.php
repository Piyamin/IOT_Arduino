<?php
$conn = new mysqli('127.0.0.1', 'u134026110_admin', '@Admin007', 'u134026110_thing');
$id = $_POST['id'];
$name = $_POST['name'];
$sql = "INSERT INTO scanfigerprint_car_miw VALUES ('$id', '$name', '0')";
$rs = $conn->query($sql);
echo json_encode($rs);
?>