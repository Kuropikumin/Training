<?php
    if( isset( $_GET['url'] ) ) {
        header( 'Content-Type: text/xml' );
        echo file_get_contents( "http://" . sanitizeString( $_GET['url'] ) );
    }
    
    function SanitizeString( $str )
    {
        $str = strip_tags( $str );
        $str = htmlentities( $str );
        return stripslashes( $str );
    }
?>
