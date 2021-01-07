<?php
    $arr = array('hoge', 'fuga', 'piyo');

    for($i = 0; $i < count($arr); $i++) echo "$i : $arr[$i] <br>";
    print_r($arr);

    $arr2 = array(
                    'hoge' => "hogehoge",
                    'fuga' => "fugafuga",
                    'piyo' => "piyopiyo"
                 );
    
    for($i = 0; $i < count($arr); $i++) echo "$i : " . $arr2[$arr[$i]]  . "<br>\n";
    print_r($arr2);
?>
