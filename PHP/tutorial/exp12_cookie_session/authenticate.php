<?php
    require_once 'login.php';
    $mysqli = new mysqli( $db_hostname, $db_username, $db_password, $db_database );
    if ( $mysqli->connect_error ) {
        echo 'Connect Error (' . $mysqli->connect_errno . ') ' . $mysqli->connect_error ;
        exit();
    }

    if( isset( $_SERVER['PHP_AUTH_USER'] ) &&
        isset( $_SERVER['PHP_AUTH_PW']   ) ) {
        $un_temp = mysql_entities_fix_string( $mysqli, $_SERVER['PHP_AUTH_USER'] );
        $pw_temp = mysql_entities_fix_string( $mysqli, $_SERVER['PHP_AUTH_PW'] );

        $query = "SELECT * FROM users WHERE username='$un_temp'";
        $result = $mysqli->query( $query );

        if( !$result ) die ("Query Error: $mysqli->error");
        else {
            $user_info = $result->fetch_array();
            $salt      = "qm&h*";
            $token     = crypt( $pw_temp, $salt );

            echo "token: $token<br />\n";

            if( $token == $user_info['password'] ) {
                echo "{$user_info['forename']} {$user_info['surname']} : Hi {$user_info['forename']}, you are now logged in as '{$user_info['username']}'";
            }
            else die( "Invalid username/password combination" );
        }
    }
    else {
        header('WWW-Authenticate: Basic realm="Restricated Section"');
        header('HTTP/1.0 401 Unauthorized');
        die("Please enter your username and password");
    }

    $mysqli->close();

    function mysql_entities_fix_string( $mysqli, $str )
    {
        return htmlentities( mysql_fix_string( $mysqli, $str ) );
    }

    function mysql_fix_string( $mysqli, $str )
    {
        if( get_magic_quotes_gpc()) $str = stripslashes( $str );
        return $mysqli->real_escape_string( $str );
    }

?>
