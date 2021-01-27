<?php
    $appname = "Kuropikumin App";

    function createMySQLi()
    { 
        require 'db_env.php';
        $mysqli = new mysqli( $dbhost, $dbuser, $dbpass );
        if( $mysqli->connect_error ) {
            echo $mysqli->connect_error;
            exit();
        }
        $mysqli->select_db( $dbname );
        if( $mysqli->error) {
            echo $mysqli->connect_error;
            exit();
        }
        return $mysqli;
    }

	function createTable( $name, $query )
	{
		queryMysql( "CREATE TABLE IF NOT EXISTS $name( $query )" );
		echo "Table '$name' created or already exists.<br />";
	}

	function queryMysql( $query )
	{
        $mysqli = createMySQLi();
		$result = $mysqli->query( $query );
 		if( !$result ) die ("Query Error: $mysqli->error");
        $mysqli->close();
		return $result;
	}

	function destroySession()
	{
		$_SESSION = array();
		if( session_id() != "" || isset( $_COOKIE[session_name()] ) ) {
			setcookie( session_name(), '', time() - 2592000, '/' );
		}
		session_destroy();
	}

	function sanitizeString( $str )
	{
        $mysqli = createMySQLi();
		$str = strip_tags( $str );
		$str = htmlentities( $str );
		$str = stripslashes( $str );
		$str = $mysqli->real_escape_string( $str );
        $mysqli->close();
		return $str;
	}

	function showProfile( $user )
	{
        $user_file = "img/user/$user.jpg";
		if( file_exists( $user_file ) ) {
			echo "<img src='$user_file' aligin='left' /><br />";
		}

		$result = queryMysql( "SELECT * FROM profiles WHERE user='$user'" );
		if( $result->num_rows ) {
			$row = $result->fetch_row();
			echo stripslashes( $row[1] ) . "<br clear='left' /><br />";
		}
	}
?>
