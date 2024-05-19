<?php

    $nume = $_POST['nume'];
    $prenume = $_POST['prenume'];
    $varsta = $_POST['varsta'];
    $salar_brut = $_POST['salar_brut'];
    $salar_net = $salar_brut * 0.84;

    $conn = mysqli_connect("localhost", "root", "") 
        or die("Could not connect to the databse.");

    mysqli_select_db($conn, "evidenta") or die("Could not select database.");

    $insert_query = "insert into angajati (nume, prenume, varsta, salar_brut, salar_net) values ('$nume', '$prenume', $varsta, $salar_brut, $salar_net);";
    $conn->query($insert_query);

    print("<center>Angajati dupa inserare</center> <br>");
    $describe_query = "describe angajati;";
    $result = $conn->query($describe_query);
    print('<table align=center BORDER="2">'); 
    print ("<tr>"); 
    foreach ($result as $row) {
        echo '<th BGCOLOR="Silver">' . $row['Field'] . '</th>'; 
    }
    print ("</tr>"); 

    $query = "select * from angajati;";
    $result = $conn->query($query);

    foreach ($result as $row) {
        print ("<tr>");
        foreach ($row as $value) {
            print ("<td>$value</td>");
        }
        print ("</tr>");
    }

    print("</table>");
    $conn->close();
    echo "Inserted OK! <br>";
    echo '<input type="button" value="Go back" onclick="window.location.href=\'index.php\'" />';
?>