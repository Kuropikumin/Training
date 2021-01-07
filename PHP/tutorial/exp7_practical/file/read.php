<?php
    $fh = fopen('./textfile/testfile.txt', 'r') or die("Can't open [./textfile/testfile.txt] file!");
    $line = fgets($fh);
    fclose($fh);
    echo $line;
?>
