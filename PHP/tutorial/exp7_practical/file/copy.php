<?php
    $file_path = "./textfile/testfile.txt";
    copy($file_path, $file_path . ".cp") or die ("Can't copy [$file_path] file!");
    echo "File successfully copied to " . $file_path . ".cp<br>\n";

?>
