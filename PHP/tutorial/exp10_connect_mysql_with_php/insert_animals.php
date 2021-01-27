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

    $query = "INSERT INTO cats VALUES(NULL, 'Lion', 'Leo', 4), (NULL, 'Cougar', 'Growler', 2), (NULL, 'Cheetah', 'Charlie', 3)";
    $result = $mysqli->query( $query );
    if( !$result ) die ("Query Error: $mysqli->error");

?>
