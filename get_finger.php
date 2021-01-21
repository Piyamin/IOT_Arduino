<?php
$conn = new mysqli('127.0.0.1', 'u134026110_admin', '@Admin007', 'u134026110_thing');
$sql= "SELECT MAX(ID) as id FROM `scanfigerprint_car_miw`";
$rs = $conn->query($sql);
$data = array();
while ($row = $rs->fetch_array()) {
    array_push($data, $row);
}
print json_encode($data);
?>