<?php

    $username = "sys as sysdba";
    $password = "orcl";

    $conn = oci_connect($username, $password, 'localhost/orcl');

    if (!$conn) {
        $e = oci_error();
        trigger_error(htmlentities($e['message'], ENT_QUOTES), E_USER_ERROR);
    }
    else {
        echo "Connected to Oracle!";
    }
?>