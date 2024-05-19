<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <title>Laborator 2</title>
  <link rel="stylesheet" href="./style.css">
</head>

<body>

<?php 

    $nr_vanzari = 0;
    $total_vanzari = 0;

    $conn = mysqli_connect("localhost", "root", "") 
    or die("Could not connect to the databse.");

    mysqli_select_db($conn, "evidenta") or die("Could not select database.");

    $describe_query = "describe evidenta_carte;";
    $result = $conn->query($describe_query);
    print('<table align=center BORDER="2">'); 
    print ("<tr>"); 
    foreach ($result as $row) {
        echo '<th BGCOLOR="Silver">' . $row['Field'] . '</th>'; 
    }
    print ("</tr>"); 

    $query = "select * from evidenta_carte;";
    $result = $conn->query($query);

    foreach ($result as $row) {
        print ("<tr>");
        foreach ($row as $value) {
            print ("<td>$value</td>");
        }
        print ("</tr>");

        $nr_vanzari += $row['nr_exemplare_vandute'];
        $total_vanzari += $row['pret_total_carte'];
    }

    print("</table>");
    print("<br>");
    print("<center>");
    print("Nr. carti vandute: $nr_vanzari <br>");
    print("Suma totala incasata: $total_vanzari <br>");
    print("</center>");

    $conn->close();
?>


    <br>
    <center>
        <input type="button" value="Inserare" onclick="window.location.href='inserare.html'" />
        <input type="button" value="Sterge" onclick="window.location.href='sterge_titlu.html'" />
        <input type="button" value="Vanzare" onclick="window.location.href='vanzare.html'" />
    </center>

</body>

</html>