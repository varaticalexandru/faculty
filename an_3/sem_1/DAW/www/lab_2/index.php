<?php


    $nume_produs = $_POST['nume_produs'];
    $query = "select * from produs where nume_produs = '$nume_produs';";
    $cantitate = 0;
    $pret = 0.0;
    $produs = 0.0;

    $con = mysqli_connect("localhost", "root", "")
        or die ("Could not connect to database");

    mysqli_select_db($con, "mydb") or die("Can not select database"); 


    print('<table align=center BORDER="2">'); 
    print ("<tr>"); 
    echo '<th BGCOLOR="Silver">ID</th>'; 
    echo '<th BGCOLOR="Silver">Nume produs</th>'; 
    echo '<th BGCOLOR="Silver">Pret</th>'; 
    echo '<th BGCOLOR="Silver">Cantitate</th>'; 
    print ("</tr>"); 



    $result = $con->query($query);

    foreach($result as $row)
    { 

        $pret = $row['pret'];
        $cantitate = $row['cantitate'];

        print ("<tr>"); 

        foreach ($row as $value) {
            print ("<td>$value</td>");
        }
        print ("</tr>"); 
    }

    print ("</table>");

    print ("<br><br");

    print("<div>Cantitate: $cantitate <div>");
    print("<div>Pret: $pret <div>");

    $produs = $cantitate * $pret;
    print("<div>Pret * Cantitate: $produs <div>");

    $con->close();


?>