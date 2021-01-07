<?php
    $arr = array(
            'hoge' => array(
                'hoge1' => 'hoge',
                'hoge2' => 'hogehoge',
                'hoge3' => 'hogehogehoge'
            ),

            'fuga' => array(
                'fuga1' => 'fuga',
                'fuga2' => 'fugafuga',
                'fuga3' => 'fugafugafuga'
            ),

            'piyo' => array(
                'piyo1' => 'piyo',
                'piyo2' => 'piyopiyo',
                'piyo3' => 'piyopiyopiyo'
            )
    );
    echo "\$arr is > <br>\n";
    print_r($arr);
    echo "<br>\n";

    $val = 'hogehoge';
    if(is_array($arr)) echo "arr is array<br>\n"; else echo "arr is not array<br>\n";
    if(is_array($val)) echo "val is array<br>\n"; else echo "val is not array<br>\n";
    echo "val2 is not defined.<br>\n";
    if(is_array($val2)) echo "val2 is array<br>\n"; else echo "val2 is not array<br>\n";
    echo 'count($arr) is ' . count($arr) . "<br>\n";
    echo 'count($arr, 1) is ' . count($arr, 1) . "<br>\n";
    echo "<br>\n";
?>
