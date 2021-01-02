<?php
    $time_now = time();
    echo "time() > " . time() . "<br>\n";
    echo "mktime(0, 0, 0, 1, 1, 2000) > ";
    echo mktime(0, 0, 0, 1, 1, 2000);
    echo "<br>\n";
    $sec  = $time_now%60;
    $min  = ($time_now/60)%60;
    $hour = ($time_now/3600)%24;
    echo "$hour:$min:$sec(GMT)<br>\n";
    $hour += 9;
    echo "$hour:$min:$sec(JST)<br>\n";
?>
