<?php
    $name1 = "WILLIAM";
    $name2 = "henry";
    $name3 = "gatES";
    echo "before > " . $name1 . " : " . $name2 . " : " . $name3 . "<br>\n";
    fix_name($name1, $name2, $name3);
    echo "after  > " . $name1 . " : " . $name2 . " : " . $name3 . "<br>\n";

    function fix_name(&$name1, &$name2, &$name3)
    {
        $name1 = ucfirst(strtolower($name1));
        $name2 = ucfirst(strtolower($name2));
        $name3 = ucfirst(strtolower($name3));
    }
?>
