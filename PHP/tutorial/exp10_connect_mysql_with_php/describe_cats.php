<?php
    require_once 'login.php';
    $mysqli = new mysqli( $db_hostname, $db_username, $db_password );
    if( $mysqli->connect_error) {
        echo $mysqli->connect_error;
        exit();
    }
    $mysqli->select_db( $db_database );
    if( $mysqli->error) {
        echo $mysqli->connect_error;
        exit();
    }

    $mysqli->set_charset( "utf-8" );

    $query = 'DESCRIBE cats';
    $result = $mysqli->query( $query );
    if( !$result ) die ("Query Error: $mysqli->error");

    echo "<table><tr> <th>Column</th> <th>Type</th> <th>Null</th> <th>Key</th> </tr>";
    while( $row = $result->fetch_row() ) {
        echo "<tr>";
        for($i = 0; $i < count($row); $i++) {
            echo "<td>$row[$i]</td>";
        }
        echo "</tr>";
    }
?>
