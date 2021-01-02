<?php
    $arr = array('hoge' => 'hogehoge', 'fuga' => 'fugafuga', 'piyo' => 'piyopiyo');
    print_r($arr);
    echo "<br>\n";

    echo current($arr) . "<br>\n";

    echo "next(\$arr) > ";
    next($arr);
    echo current($arr) . "<br>\n";

    echo "next(\$arr) > ";
    next($arr);
    echo current($arr) . "<br>\n";

    echo "next(\$arr) > ";
    next($arr);
    echo current($arr) . "<br>\n";

    echo "reset(\$arr) > ";
    reset($arr);
    echo current($arr) . "<br>\n";

    echo "next(\$arr) > ";
    next($arr);
    echo current($arr) . "<br>\n";

    echo "next(\$arr) > ";
    next($arr);
    echo current($arr) . "<br>\n";

    echo "reset(\$arr) > ";
    reset($arr);
    echo current($arr) . "<br>\n";

    echo "end(\$arr) > ";
    end($arr);
    echo current($arr) . "<br>\n";
?>
