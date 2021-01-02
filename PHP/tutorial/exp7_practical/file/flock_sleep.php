<?php
    $file_path = './textfile/testfile.txt';
    $fh = fopen( $file_path, 'r+') or die( "Can't open [$file_path] file!" );
    $text = rtrim( fgets( $fh ), "\n" ) . " new!!!";

    if(flock($fh, LOCK_EX)) {
        sleep( 20 );
        fseek( $fh, 0, SEEK_END );
        fwrite( $fh, $text );
        flock( $fh, LOCK_UN );
    }

    fclose( $fh );
    echo "File [$file_path] successfully updated!<br>\n";
?>
