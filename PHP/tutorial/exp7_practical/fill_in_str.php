<?php
    echo "<pre>";
    $str = 'House';
    echo "\$str is [$str]<br>\n";

    printf("[%s]", $str);
    echo " : [%s]<br>\n";

    printf("[%10s]", $str);
    echo " : [%10s]<br>\n";

    printf("[%-10s]", $str);
    echo " : [%-10s]<br>\n";

    printf("[%010s]", $str);
    echo " : [%010s]<br>\n";

    printf("[%'#10s]", $str);
    echo " : [%'#10s]<br>\n";

    echo "<br>\n";
    $str = 'Doctor House';
    echo "\$str is [$str]<br>\n";

    printf("[%10.8s]", $str);
    echo " : [%10.8s]<br>\n";

    printf("[%-10.6s]", $str);
    echo " : [%-10.6s]<br>\n";

    printf("[%-'@10.6s]", $str);
    echo " : [%-'@10.6s]<br>\n";

?>
