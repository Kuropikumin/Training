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

    $query = "DELETE FROM cats WHERE name='Growler'";
    $result = $mysqli->query( $query );
    if( !$result ) die ("Query Error: $mysqli->error");

?>
