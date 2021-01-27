<?php
    echo <<<_END
<html>
    <head>
        <title>フォームテスト</title>
    </head>
    <body>
        <form method="post" action="formtest.php">
        あなたの名前は？
        <input type="text" name="name" />
        <input type="submit" />
        </form>
    </body>
</html>
_END;
?>
