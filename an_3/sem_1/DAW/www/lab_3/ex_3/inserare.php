<?php

    $titlu_carte = $_POST['titlu_carte'];
    $autor_carte = $_POST['autor_carte'];
    $editura = $_POST['editura'];
    $cod_isbn = $_POST['cod_isbn'];
    $anul_aparitiei = $_POST['anul_aparitiei'];
    $nr_exemplare_stoc = $_POST['nr_exemplare_stoc'];
    $pret = $_POST['pret'];
    $nr_exemplare_vandute = $_POST['nr_exemplare_vandute'];
    $pret_total_carte = $pret * $nr_exemplare_vandute;


    $conn = mysqli_connect("localhost", "root", "") 
        or die("Could not connect to the databse.");

    mysqli_select_db($conn, "evidenta") or die("Could not select database.");

    $insert_query = "insert into evidenta_carte 
        (titlu_carte, autor_carte, editura, cod_isbn, anul_aparitiei, nr_exemplare_stoc, pret, nr_exemplare_vandute, pret_total_carte) 
        values (
            '$titlu_carte', 
            '$autor_carte', 
            '$editura', 
            '$cod_isbn', 
            $anul_aparitiei, 
            $nr_exemplare_stoc, 
            $pret, 
            $nr_exemplare_vandute, 
            $pret_total_carte
        );";

    $conn->query($insert_query);

    $conn->close();

    echo "Inserted OK! <br>";
    echo '<input type="button" value="Go back" onclick="window.location.href=\'index.php\'" />';
?>