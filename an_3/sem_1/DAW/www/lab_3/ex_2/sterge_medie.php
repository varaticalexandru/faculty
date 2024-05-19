<?php

    $media = $_POST['media'];
    
    $conn = mysqli_connect("localhost", "root", "") 
        or die("Could not connect to the databse.");

    mysqli_select_db($conn, "evidenta") or die("Could not select database.");

    $query = "select * from student where media < $media;";
    $result_select = $conn->query($query);
    $nr_inregistrari = $result_select->num_rows;

    echo '<center>S-au gasit ' . $nr_inregistrari . ' inregistrari cu media < ' . $media . '</center><br>';

    if ($nr_inregistrari > 0) {
        $describe_query = "describe student;";
        $result_describe = $conn->query($describe_query);
        print('<table align=center BORDER="2">'); 
        print ("<tr>"); 
        foreach ($result_describe as $row) {
            echo '<th BGCOLOR="Silver">' . $row['Field'] . '</th>'; 
        }
        print ("</tr>"); 
    
        foreach ($result_select as $row) {
            print ("<tr>");
            foreach ($row as $value) {
                print ("<td>$value</td>");
            }
            print ("</tr>");
        }
    
        print("</table>");

        echo '<br>';

        echo '<form method="POST" action="sterge_efectiv.php">'; 
        echo '<input type="hidden" name="media" value='.$_POST['media'].'>'; 
        echo '<input type="SUBMIT" value="Stergere efectiva!" >'; 
        echo '<br>'; 
        echo '</form>'; 
    }


    $conn->close();

    echo '<input type="button" value="Go back" onclick="window.location.href=\'index.php\'" />';
?>