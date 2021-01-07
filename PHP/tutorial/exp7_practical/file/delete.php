<?php
    $file_path = './textfile/testfile.txt.cp.rename';
    if( !unlink( $file_path ) ) echo "Could not delete [$file_path] file!<br>\n";
    else                        echo "File successfully deleted [$file_path] file!<br>\n";
?>
