<?php
    $file_path = "./textfile/testfile.txt";
    $fh = fopen( $file_path, 'r+') or die ("Failed open [$file_path] file!<br>\n");
    $text = fgets($fh);
    fseek( $fh, 0, SEEK_END);
    fwrite( $fh, "$text" ) or die( "Could not write to [$file_path] file!<br>\n");
    fclose( $fh );
    echo "File [$file_path] successfully updated!";
?>
