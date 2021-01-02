<?php
    $cmd = "ls -al";
    exec( escapeshellcmd( $cmd ), $output, $status );
    if( $status ) echo "Exec command failed!<br>\n";
    else {
        echo "<pre>";
        foreach( $output as $line ) echo $line . "<br>\n";
    }

?>
