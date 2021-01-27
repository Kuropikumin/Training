<?php
    session_start();
    echo "<!DOCTYPE html>\n<html><head><script src='js/myjs.js'></script>";
    echo "<!-- UIkit CSS -->" .
         "<link rel='stylesheet' href='https://cdn.jsdelivr.net/npm/uikit@3.6.13/dist/css/uikit.min.css' /> " .
         "<!-- UIkit JS -->" .
         "<script src='https://cdn.jsdelivr.net/npm/uikit@3.6.13/dist/js/uikit.min.js'></script>" .
         "<script src='https://cdn.jsdelivr.net/npm/uikit@3.6.13/dist/js/uikit-icons.min.js'></script>";
    include_once 'functions.php';

    $userstr = '( Guest )';

    if( isset( $_SESSION['user'] ) ) {
        $user     = $_SESSION['user'];
        $loggedin = TRUE;
        $userstr  = "( $user )";
    }
    else $loggedin = FALSE;

    echo "<title>$appname $userstr</title>" . 
         "<link rel='stylesheet' href='css/style.css' type='text/css' />" .
         "</head><body><div class='uk-heading-primary appname'>$appname $userstr</div>";

    if( $loggedin ) {
        echo "<br ><ul class='menu'>" .
             "<li><a href='members.php?view=$user'>Home</a></li>" .
             "<li><a href='members.php'>Members</a></li>" .
             "<li><a href='friends.php'>Friends</a></li>" .
             "<li><a href='messages.php'>Messages</a></li>" .
             "<li><a href='profile.php'>Profiles</a></li>" .
             "<li><a href='logout.php'>Log out</a></li></ul><br />";
    }
    else {
        echo "<br ><ul class='menu'>" .
             "<li><a href='index.php'>Home</a></li>" .
             "<li><a href='signup.php'>Sign up</a></li>" .
             "<li><a href='login.php'>Log in</a></li></ul><br />" .
             "<span class='info'>&#8658; You must be logged in to view this page.</span><br /><br />";
    }
?>
