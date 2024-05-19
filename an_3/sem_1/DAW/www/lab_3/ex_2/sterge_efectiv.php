<?php
    $media = $_POST['media'];

    $conn = mysqli_connect("localhost", "root", "") 
        or die("Could not connect to the databse.");

    mysqli_select_db($conn, "evidenta") or die("Could not select database."); 
    
    $query = "select * from student where media < $media;";
    $result_select = $conn->query($query);

    foreach ($result_select as $row) {
        $delete_query = "delete from student where id = " . $row['id'] . ";";
        $conn->query($delete_query);
    }

    $conn->close();

    echo "Deleted OK! <br>";

    echo '<input type="button" value="Go back" onclick="window.location.href=\'index.php\'" />';
?>