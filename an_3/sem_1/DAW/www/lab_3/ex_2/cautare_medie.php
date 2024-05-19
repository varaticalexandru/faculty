<?php

    $media = $_POST['media'];
    print("<center>Studentii cu media > $media</center> <br>");

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

    $query = "select * from student where media > $media;";
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

    echo '<input type="button" value="Go back" onclick="window.location.href=\'index.php\'" />';

?>