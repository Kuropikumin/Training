<?php
    require_once 'login.php';
    $mysqli = new mysqli( $db_hostname, $db_username, $db_password, $db_database );
    if ( $mysqli->connect_error ) {
        echo 'Connect Error (' . $mysqli->connect_errno . ') ' . $mysqli->connect_error ;
        exit();
    }

    $mysqli->set_charset( "utf-8" );

    $query = "CREATE TABLE users (
                forename VARCHAR(32) NOT NULL,
                surname  VARCHAR(32) NOT NULL,
                username VARCHAR(32) NOT NULL UNIQUE,
                password VARCHAR(32) NOT NULL
              )";

    $result = $mysqli->query( $query );
    if( !$result ) die ("Query Error: $mysqli->error");

    $salt = "qm&h*";

    $forenames = array( 'Bill',     'Pauline' );
    $surnames  = array( 'Smith',    'Jones' );
    $usernames = array( 'bsmith',   'pjones' );
    $passwords = array( 'mysecret', 'acrobat' );

    for( $i = 0; $i < count( $forenames ); $i++ ) {
        $token = crypt( $passwords[$i], $salt );
        echo $token . "<br />\n";
        add_user( $mysqli, $forenames[$i], $surnames[$i], $usernames[$i], $token );
    }

    $mysqli->close();

    function add_user( $mysqli, $fn, $sn, $un, $pw )
    {
        $query = "INSERT INTO users VALUES('$fn', '$sn', '$un', '$pw')";
        $result = $mysqli->query( $query );
        if( !$result ) die ("Query Error: $mysqli->error");
    }
?>
