<?php
    if( isset( $_POST['name'] ) ) $name = $_POST['name'];
    else $name = "未入力";
    echo <<<_END
<html>
    <head>
        <title>フォームテスト</title>
    </head>
    <body>
        <h1> あなたの名前: $name </h1><br />
        <form method="post" action="formtest2.php">
        あなたの名前は？
        <input type="text" name="name" />
        <input type="submit" />
        </form>
    </body>
</html>
_END;
?>
