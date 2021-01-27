<?php
    session_start();
    if( isset( $_SESSION['username'] ) ) {
        $username = $_SESSION['username'];
        $password = $_SESSION['password'];
        $forename = $_SESSION['forename'];
        $surname  = $_SESSION['surname'];

        destroy_session_and_data();

        echo "Welcome back $forename. <br />
              Your full name is $forename $surname. <br />
              Your username is '$username' and password is '$password'.";
    }
    else {
        echo "Please <a href=session.php>click here</a> to log in.";
    }

    function destroy_session_and_data() {
        echo "session_name = " . session_name() . "<br />\n";
        $_SESSION = array();
        setcookie( session_name(), '', time() - 60*60*24*30, '/' );
        session_destroy();
    }
?>
