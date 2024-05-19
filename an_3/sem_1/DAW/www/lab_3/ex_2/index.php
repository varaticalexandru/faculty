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
    $conn = mysqli_connect("localhost", "root", "") 
    or die("Could not connect to the databse.");

    mysqli_select_db($conn, "evidenta") or die("Could not select database.");

    $describe_query = "describe student;";
    $result = $conn->query($describe_query);
    print('<table align=center BORDER="2">'); 
    print ("<tr>"); 
    foreach ($result as $row) {
        echo '<th BGCOLOR="Silver">' . $row['Field'] . '</th>'; 
    }
    print ("</tr>"); 

    $query = "select * from student;";
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
  ?>


    <br>
    <br>
    <center>
        <input type="button" value="Actualizare medie" onclick="window.location.href='actualizare_medie.php'" />
        <input type="button" value="Cautare" onclick="window.location.href='./cautare_medie.html'" />
        <input type="button" value="Stergere" onclick="window.location.href='./sterge_medie.html'" />
        <input type="button" value="Inserare" onclick="window.location.href='./inserare.html'" />
        <input type="button" value="Nepromovati" onclick="window.location.href='./nepromovati.php'" />
    </center>

</body>

</html>