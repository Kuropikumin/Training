<?php
    echo "<pre>";
    $time_now = time();
    echo "date(\"l F jS, Y - g:ia\", \$time_now) > ";
    echo date("l F jS, Y - g:ia<br>\n", $time_now);

    echo "date(DATE_ATOM, \$time_now)          > ";
    echo date(DATE_ATOM, $time_now);
    echo "\n";

    echo "date(DATE_COOKIE, \$time_now)        > ";
    echo date(DATE_COOKIE, $time_now);
    echo "\n";

    echo "date(DATE_RSS, \$time_now)           > ";
    echo date(DATE_RSS, $time_now);
    echo "\n";

    echo "date(DATE_W3C, \$time_now)           > ";
    echo date(DATE_W3C, $time_now);
    echo "\n";

?>
