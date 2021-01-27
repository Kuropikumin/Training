<?php
    include_once 'header.php';

    if( !$loggedin ) die();

    echo "<div class='main'>";

    if( isset( $_GET['view'] ) ) {
        $view = sanitizeString( $_GET['view'] );

        if( $view == $user ) $name = 'Your';
        else                 $name = "$view's";

        echo "<h3>$name Profile</h3>";
        showProfile( $view );

        echo "<a class='button' href='messages.php?view=$view'>" .
             "View $name messages</a><br /><br />";

        die( "</div></body></html>" );
    }

    if( isset( $_GET['add'] ) ) {
        $add = sanitizeString( $_GET['add'] );

        $result = queryMysql( "SELECT * FROM members ORDER BY user" );

        if( $result->num_rows ) {
            queryMysql( "INSERT INTO friends VALUES( '$add', '$user' )" );
        }
    }
    elseif( isset( $_GET['remove'] ) ) {
        $remove = sanitizeString( $_GET['remove'] );
        queryMysql( "DELETE FROM friends WHERE user='$remove' AND friend='$user'" );
    }
    $result = queryMysql( "SELECT user FROM members ORDER BY user" );
    $num    = $result->num_rows;

    echo "<h3>Other Members</h3><ul>";

    for( $j = 0; $j < $num; $j++ ) {
        $row = $result->fetch_row();
        if( $row[0] == $user ) continue;

        echo "<li><a href='members.php?view=$row[0]'>$row[0]</a>";
        $follow = 'follow';

        $other_follow_data = queryMysql( "SELECT * FROM friends WHERE user='$row[0]' AND friend='$user'" );
        $my_follow_data    = queryMysql( "SELECT * FROM friends WHERE user='$user' AND friend='$row[0]'" );

        $other_follow_num = $other_follow_data->num_rows;
        $my_follow_num    = $my_follow_data->num_rows;

        if( ( $other_follow_num + $my_follow_num ) > 1 ) echo " &harr; is a mutual friend";
        elseif( $other_follow_num )                      echo " &larr; you are following";
        elseif( $my_follow_num ) {
            echo " &rarr; is following you";
            $follow = "recip";
        }

        if( !$other_follow_num ) echo " [<a href='members.php?add="    . $row[0] . "'>$follow</a>]";
        else                     echo " [<a href='members.php?remove=" . $row[0] . "'>$drop</a>]";
    }
?>

<br /></div></body></html>
