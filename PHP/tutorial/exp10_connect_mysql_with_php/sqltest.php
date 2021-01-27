<?php
    require_once 'login.php';
    $db_server = mysqli_connect( $db_hostname, $db_username, $db_password );
    if(!$db_server) die("Unable to connect to MySQL: \n" . mysqli_error());
    else echo "Connect $db_hostname MySQL!<br>\n";

    mysqli_select_db( $db_server, $db_database ) or die("Unable to select database: $db_database\n" . mysqli_error());

    $query = 'SELECT * FROM classics';
    $result = mysqli_query( $db_server, $query );
    if(!$result) die ("$db_database Database access failed: " . mysqli_error());

    if( isset( $_POST['delete'] ) && isset( $_POST['isbn'] ) ){
        $isbn  = get_post( $db_server, 'isbn' );
        $query = "DELETE FROM classics WHERE isbn='$isbn'";

        if(!mysqli_query( $db_server, $query )) {
            echo "DELETE Failed: $query <br />" . mysqli_error() . "<br /><br />";
        }
        else echo "Success Delete isbn: $isbn <br />";

    }

    if( isset( $_POST['author'] )   &&
        isset( $_POST['title'] )    &&
        isset( $_POST['category'] ) &&
        isset( $_POST['year'] )     &&
        isset( $_POST['isbn'] ) ) {
        $author   = get_post( $db_server, 'author' );
        $title    = get_post( $db_server, 'title' );
        $category = get_post( $db_server, 'category' );
        $year     = get_post( $db_server, 'year' );
        $isbn     = get_post( $db_server, 'isbn' );

        $query = "INSERT INTO classics VALUES " .
                 "('$author', '$title', '$category', '$year', '$isbn')";

        if(!mysqli_query( $db_server, $query )) {
            echo "INSERT Failed!: $query <br />" . mysqli_error() . "<br /><br />";
        }
        else echo "Success Insert: ('$author', '$title', '$category', '$year', '$isbn') <br />";
    }

    echo <<<_END
<form action="sqltest.php" method="post"><pre>
　　著者 <input type="text" name="author" />
タイトル <input type="text" name="title" />
カテゴリ <input type="text" name="category" />
　　　年 <input type="text" name="year" />
　　ISBN <input type="text" name="isbn" />
         <input type="submit" value="レコードの追加" />
</pre></form>
_END;

    $query  = "SELECT * FROM classics";
    $result = mysqli_query( $db_server, $query );
    if( !$result ) die ("$db_database Database access failed: " . mysqli_error());

    for( $i = 0; $i < $result->num_rows; $i++) {
        $result_arr = $result->fetch_array();
        echo <<<_END
<pre>
　　著者 {$result_arr['author']}
タイトル {$result_arr['title']}
カテゴリ {$result_arr['category']}
　　　年 {$result_arr['year']}
　　ISBN {$result_arr['isbn']}
</pre>
<form action="sqltest.php" method="post">
<input type="hidden" name="delete" value="yes" />
<input type="hidden" name="isbn" value="{$result_arr['isbn']}" />
<input type="submit" value="レコードの消去" /></form>
_END;
    }

    function get_post( $db_server, $str )
    {
        return mysqli_real_escape_string( $db_server, $_POST[$str] );
    }

    mysqli_close( $db_server );
?>
