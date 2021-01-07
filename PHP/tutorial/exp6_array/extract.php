<?php
    $piyo = 100;
    echo "\$piyo = $piyo <br>\n";
    $arr = array('hoge' => 'hogehoge', 'fuga' => 'fugafuga', 'piyo' => 'piyopiyo');
    $ext_arr = extract($arr);
    print_r($arr);
    echo"<br>\n";
    echo "\$ext_arr = extract(\$arr) > " . $ext_arr . "<br>\n";
    echo "\$piyo = $piyo <br>\n";
    echo "<br>\n";
?>
