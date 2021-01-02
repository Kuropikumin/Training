<?php
    $a = 10;
    $b = TRUE;
    $c = "hogehoge";
    echo "before > " . $a . " : " . $b . " : " . $c . "<br>\n";
    global_change();
    echo "after  > " . $a . " : " . $b . " : " . $c . "<br>\n";

    function global_change()
    {
        global $a; $a = 30;
        global $b; $b = FALSE;
        global $c; $c = 'fugafuga';
    }
?>
