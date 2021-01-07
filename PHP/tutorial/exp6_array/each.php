<?php
    $arr = array('hoge' => 'hogehoge', 'fuga' => 'fugafuga', 'piyo' => 'piyopiyo');
    print_r($arr);
    echo "<br>\n";

    echo "each(\$arr) > ";
    list($key, $value) = each($arr);
    echo  "(\$key, \$value) = ($key, $value)<br>\n";

    echo "each(\$arr) > ";
    list($key, $value) = each($arr);
    echo  "(\$key, \$value) = ($key, $value)<br>\n";

    echo "each(\$arr) > ";
    list($key, $value) = each($arr);
    echo  "(\$key, \$value) = ($key, $value)<br>\n";

    echo "current(\$arr) > " . current($arr) . "<br>\n";
?>
