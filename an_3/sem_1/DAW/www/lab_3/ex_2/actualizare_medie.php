<?php
    $conn = mysqli_connect("localhost", "root", "") 
        or die("Could not connect to the databse.");

    mysqli_select_db($conn, "evidenta") or die("Could not select database.");

    $query = "select * from student;";
    $result = $conn->query($query);

    foreach($result as $row) {
        $id = $row['id'];
        $nota1 = $row['nota1'];
        $nota2 = $row['nota2'];
        $media = ($nota1 + $nota2) / 2;
        $query = "update student set media = $media where id = $id;";
        $conn->query($query);
    }

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

    print('</table>');
    print('Updated OK!' . '<br>');
    $conn->close();

    
    echo '<input type="button" value="Go back" onclick="window.location.href=\'index.php\'" />';
?>