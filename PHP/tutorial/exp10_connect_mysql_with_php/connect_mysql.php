<?php
    require_once 'login.php';
    $db_server = mysqli_connect( $db_hostname, $db_username, $db_password );
    if(!$db_server) die("Unable to connect to MySQL: \n" . mysqli_error());
    else echo "Connect $db_hostname MySQL!\n";

    mysqli_select_db( $db_server, $db_database ) or die("Unable to select database: $db_database\n" . mysqli_error());

    $query = 'SELECT * FROM classics';
    $result = mysqli_query( $db_server, $query );
    if(!$result) die ("$db_database Database access failed: " . mysqli_error());
    else {
        print_r( $result );
    }

    mysqli_close( $db_server );
?>
