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

    $query = 'SELECT * FROM customers';
    $result = $mysqli->query( $query );
    if( !$result ) die ("Query Error: $mysqli->error");

    while( $row = $result->fetch_row() ) {

        echo "{$row[0]} は、 ISBN {$row[1]} を購入した: <br />";
        $subquery = "SELECT * FROM classics WHERE isbn='{$row[1]}'";
        $subresult = $mysqli->query( $subquery );
        if( !$subresult ) die ("Query Error: $mysqli->error");
        $subrow = $subresult->fetch_row();
        echo " '$subrow[1]' ( $subrow[0] 著 ) <br />";
    }
?>
