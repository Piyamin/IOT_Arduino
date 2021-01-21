<?php
$conn = new mysqli('127.0.0.1', 'u134026110_admin', '@Admin007', 'u134026110_thing');
$sql= "SELECT `id`, `name` FROM `scanfigerprint_car_miw` WHERE id != '0' ";
$rs = $conn->query($sql);
$data = array();
while ($row = $rs->fetch_array()) {
    array_push($data, $row);
}
print json_encode($data);
?>