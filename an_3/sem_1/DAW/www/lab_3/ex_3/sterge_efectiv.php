<?php
    $titlu_carte = $_POST['titlu_carte'];

    echo "$titlu_carte <br>";

    $conn = mysqli_connect("localhost", "root", "") 
        or die("Could not connect to the databse.");

    mysqli_select_db($conn, "evidenta") or die("Could not select database."); 
    
    $query = "select * from evidenta_carte where titlu_carte = '$titlu_carte';";
    $result_select = $conn->query($query);

    foreach ($result_select as $row) {
        $delete_query = "delete from evidenta_carte where nr_crt = " . $row['nr_crt'] . ";";
        $conn->query($delete_query);
    }

    $conn->close();

    echo "Deleted OK! <br>";

    echo '<input type="button" value="Go back" onclick="window.location.href=\'index.php\'" />';
?>