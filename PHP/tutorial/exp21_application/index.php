<?php
    include_once 'header.php';
    echo "<br /><span class='main'>Welcome to $appname,";

    if( $loggedin) echo " $user, you are logged in.";
    else           echo ' Please sign up adn/or log in to join in.';
?>
</span><br /></body></html>
