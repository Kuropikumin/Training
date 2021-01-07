<?php
    $f = $c = "";
    if( isset( $_POST['f'] ) ) $f = sanitizeString( $_POST['f'] );
    if( isset( $_POST['c'] ) ) $c = sanitizeString( $_POST['c'] );

    if( $f != "" ) {
        $c = intval(( 5/9 )*( $f - 32 ));
        $out = "$f f は  $c c です。";
    }
    elseif( $c != "" ) {
        $f = intval(( 9/5 )*( $c + 32 ));
        $out = "$c c は  $f f です。";
    }
    else $out = "";

    echo <<<_END
<html><head><title>摂氏と華氏の変換</title></head>
<body><pre>
摂氏または華氏を入力し、変換ボタンをクリック
<b>$out</b>
<form method="post" action="convert.php">
華氏 <input type="text" name="f" size="7" />
摂氏 <input type="text" name="c" size="7" />
     <input type="submit" value="変換" />
</form></pre></body>
</html>
_END;

    function sanitizeString( $str )
    {
        echo "input > " . $str . "<br />";
        $str = stripslashes( $str );
        echo "stripslashes > " . $str . "<br />";
        $str = htmlentities( $str );
        echo "htmlentities > " . $str . "<br />";
        $str = strip_tags( $str );
        echo "strip_tags > " . $str . "<br />";
        return $str;
    }
?>
