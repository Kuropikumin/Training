<?php
    echo fix_name("WILLIAM", "henry", "gatES");

    function fix_name($name1, $name2, $name3)
    {
        $n1 = ucfirst(strtolower($name1));
        $n2 = ucfirst(strtolower($name2));
        $n3 = ucfirst(strtolower($name3));
        return $n1 . " : " . $n2 . " : " . $n3;
    }
?>
