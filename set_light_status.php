<?php
$conn = new mysqli('127.0.0.1', 'u134026110_admin', '@Admin007', 'u134026110_thing');
$sql = "UPDATE ligth_wiper_car_miw set status = '" . $_POST['status'] . "' ";
$sql .= " where name='light_car'";

$r = $conn->query($sql);

$return = array();
if (!$r) {
    $return['result'] = "ERR";
    $return['status'] = $conn->error;
} else {
    $return['result'] = "OK";
    $return['status'] = "Operation complete";
}

print json_encode($return);