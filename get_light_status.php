<?php
$conn = new mysqli('127.0.0.1', 'u134026110_admin', '@Admin007', 'u134026110_thing');
$sql= "SELECT `status`,`name` FROM `ligth_wiper_car_miw` WHERE name = 'light_car'";
$rs = $conn->query($sql);
$data = array();
while ($row = $rs->fetch_array()) {
    array_push($data, $row);
}
print json_encode($data);
?>