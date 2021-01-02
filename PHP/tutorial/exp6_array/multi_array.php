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

    foreach( $arr as $key => $value ) {
        echo $key . " > <br>\n";
        foreach( $value as $key2 => $value2 ) {
            echo $key2 . " : " . $value2 . "<br>\n";
        }
    }
    print_r($arr);
?>
