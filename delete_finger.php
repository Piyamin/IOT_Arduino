<?php
$conn = new mysqli('127.0.0.1', 'u134026110_admin', '@Admin007', 'u134026110_thing');
$id = $_POST['id'];
$name = $_POST['name'];
$sql = "DELETE FROM `scanfigerprint_car_miw` WHERE `scanfigerprint_car_miw`.`id` = $id";
$rs = $conn->query($sql);
echo json_encode($rs);
?>