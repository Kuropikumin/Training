<?php
    $file_path = './textfile/testfile.txt.cp';
    if(!rename( $file_path, $file_path . ".rename" )) echo "Could not rename [$file_path] file!<br>\n";
    else                                             echo "File successfully renamed $file_path to $file_path" . ".rename!<br>\n";
?>
