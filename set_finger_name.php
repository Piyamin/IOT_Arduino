<?php
$conn = new mysqli('127.0.0.1', 'u134026110_admin', '@Admin007', 'u134026110_thing');
$sql = "UPDATE scanfigerprint_car_miw set name = '" . $_POST['name'] . "' ";
$sql .= "WHERE id ='" . $_POST['id'] ."'";
$rs = $conn->query($sql);
echo json_encode($rs);