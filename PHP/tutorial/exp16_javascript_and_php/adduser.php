<?php
    $forename = $surname = $username = $password = $age = $email = '';

    if( isset( $_POST['forename'] ) ) $forename = fix_string( $_POST['forename'] );
    if( isset( $_POST['surname'] ) )  $surname  = fix_string( $_POST['surname'] );
    if( isset( $_POST['username'] ) ) $username = fix_string( $_POST['username'] );
    if( isset( $_POST['password'] ) ) $password = fix_string( $_POST['password'] );
    if( isset( $_POST['age'] ) )      $age      = fix_string( $_POST['age'] );
    if( isset( $_POST['email'] ) )    $email    = fix_string( $_POST['email'] );

    $fail = '';
    $fail += validate_forename( $forename );
    $fail += validate_surname( $surname );
    $fail += validate_username( $username );
    $fail += validate_password( $password );
    $fail += validate_age( $age );
    $fail += validate_email( $email );

    echo "<html><head><title>An Example Form</title>";
    if( $fail == '' ) {
        echo "</head><body>Form data successfully validated: $forename, $surname, $username, $password, $age, $email. </body></html>";
        exit;
    }

    echo <<<_END
        <style>.signup{ border: 1px solid #999999; font: normal 14px helvetica; color:#444444: }</style>
        <script type="text/javascript" src="js/validate.js"></script>
    </head>
    <body>
        <table class="signup" border="0" cellpadding="2" cellspacing="5" bgcolor="#eeeeee">
            <th colspan="2" align="center"> Signup Form </th>
            <form method="post" action="adduser.php" onsubmit="return validate( this )" >
                <tr>
                    <td>Forename</td>
                    <td><input type="text" maxlength="32" name="forename" /></td>
                </tr>
                <tr>
                    <td>Surname</td>
                    <td><input type="text" maxlength="32" name="surname" /></td>
                </tr>
                <tr>
                    <td>Username</td>
                    <td><input type="text" maxlength="16" name="username" /></td>
                </tr>
                <tr>
                    <td>Password</td>
                    <td><input type="text" maxlength="12" name="password" /></td>
                </tr>
                <tr>
                    <td>Age</td>
                    <td><input type="text" maxlength="3"  name="age" /></td>
                </tr>
                <tr>
                    <td>Email</td>
                    <td><input type="text" maxlength="64" name="email" /></td>
                </tr>
                <tr>
                    <td colspan="2" align="center"><input type="submit" value="Signup" /></td>
                </tr>
            </form>
        </table>
   </body>
</html>
_END;

    function validate_forename( $field )
    {
        if( $field == '' ) return "No Forename was entered<br />";
        return "";
    }

    function validate_surname( $field )
    {
        if( $field == '' ) return "No Surname was entered<br />";
        return "";
    }

    function validate_username( $field )
    {
        if( $field == '' ) return "No Username was entered<br />";
        else if( strlen( $field ) < 5 ) return "Usernames must be at least 5 characters<br />";
        else if( preg_match( "/[^\w-]/", $field ) ) return "Only letters, numbers, - and _ in usernames<br />";
        return "";
    }

    function validate_password( $field )
    {
        if( $field == '' ) return "No Password was entered<br />";
        else if( strlen( $field ) < 6 ) return "Password must be at least 6 characters<br />";
        else if( !preg_match( "/[a-z]/", $field ) ||
                 !preg_match( "/[A-Z]/", $field ) ||
                 !preg_match( "/[0-9]/", $field )
               ) return "Passwords require 1 each of a-z, A-Z and 0-9<br />";
        return "";
    }

    function validate_age( $field )
    {
        if( $field == '' ) return "No Age was entered<br />";
        else if( $field < 18 || 110 < $field ) return "Age must be between 18 and 110<br />";
        return "";
    }

    function validate_email( $field )
    {
        if( $field == '' ) return "No Email was entered<br />";
        else if( !( ( strpos( $field, "." ) > 0 )   &&
                    ( strpos( $field, "@" ) > 0 ) ) ||
                   preg_match( "/[^\w.@-]/", $field )
               ) return "The Email address is invalid<br />";
        echo 'preg_match( "/[^\w.@-]/", $field ) : ' + preg_match( "/[^\w.@-]/", $field );
        return "";
    }

    function fix_string( $str )
    {
        if( get_magic_quotes_gpc() ) $str = stripslashes( $str );
        return htmlentities( $str );
    }
?>
