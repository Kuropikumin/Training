<?php
    require_once 'login.php';
    $db_server = mysqli_connect( $db_hostname, $db_username, $db_password );
    if(!$db_server) die("Unable to connect to MySQL: \n" . mysqli_error());
    else echo "Connect $db_hostname MySQL!<br>\n";

    mysqli_select_db( $db_server, $db_database ) or die("Unable to select database: $db_database\n" . mysqli_error());

    $query = 'SELECT * FROM classics';
    $result = mysqli_query( $db_server, $query );
    if(!$result) die ("$db_database Database access failed: " . mysqli_error());

    echo "--------------------------------------- <br>\n";
    for( $i = 0; $i < $result->num_rows; $i++ ) {
        $array = $result->fetch_array();
        echo 'Author: '   . $array['author']   . "<br>\n";
        echo 'Title: '    . $array['title']    . "<br>\n";
        echo 'Category: ' . $array['category'] . "<br>\n";
        echo 'Year: '     . $array['year']     . "<br>\n";
        echo 'ISBN: '     . $array['isbn']     . "<br>\n";
        echo "--------------------------------------- <br>\n";
    }

    mysqli_close( $db_server );
?>
