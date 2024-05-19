<?php
    $titlu_carte = $_POST['titlu_carte'];
    $nr_exemplare = $_POST['nr_exemplare'];

    $conn = mysqli_connect("localhost", "root", "") 
        or die("Could not connect to the databse.");

    mysqli_select_db($conn, "evidenta") or die("Could not select database.");

    $query = "select * from evidenta_carte where titlu_carte = '$titlu_carte';";
    $result = $conn->query($query);

    if ($result->num_rows > 0) {
        $row = $result->fetch_assoc();
        if ($row['nr_exemplare_stoc'] >= $nr_exemplare) {
            $update_query = "update evidenta_carte set nr_exemplare_stoc = nr_exemplare_stoc - $nr_exemplare where titlu_carte = '$titlu_carte';";
            $conn->query($update_query);
            $update_query = "update evidenta_carte set nr_exemplare_vandute = nr_exemplare_vandute + $nr_exemplare where titlu_carte = '$titlu_carte';";
            $conn->query($update_query);
            $update_query = "update evidenta_carte set pret_total_carte = pret_total_carte + " . $nr_exemplare * $row['pret'] . " where titlu_carte = '$titlu_carte';";
            $conn->query($update_query);

            echo "Vanzare efectuata cu succes!";
        } else {
            echo "Nu exista suficiente exemplare in stoc!";
        }
    } else {
        echo "Nu exista cartea cu titlul $titlu_carte!";
    }

    $conn->close();

    echo '<br>
    <input type="button" value="Go back" onclick="window.location.href=\'index.php\'" />';

?>