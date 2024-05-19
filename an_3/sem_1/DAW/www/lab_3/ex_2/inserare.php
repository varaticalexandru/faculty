<?php

    $nume = $_POST['nume'];
    $prenume = $_POST['prenume'];
    $grupa = $_POST['grupa'];
    $nota1 = $_POST['nota1'];
    $nota2 = $_POST['nota2'];
    $media = ($nota1 + $nota2) / 2;

    $conn = mysqli_connect("localhost", "root", "") 
        or die("Could not connect to the databse.");

    mysqli_select_db($conn, "evidenta") or die("Could not select database.");

    $insert_query = "insert into student (nume, prenume, grupa, nota1, nota2, media) values ('$nume', '$prenume', $grupa, $nota1, $nota2, $media);";
    $conn->query($insert_query);

    print("<center>Studenti dupa inserare</center> <br>");
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
    echo "Inserted OK! <br>";
    echo '<input type="button" value="Go back" onclick="window.location.href=\'index.php\'" />';
?>