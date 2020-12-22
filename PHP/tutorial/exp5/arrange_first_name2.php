<?php
    $names = fix_name("WILLIAM", "henry", "gatES");
    echo $names[0] . " : " . $names[1] . " : " . $names[2];

    function fix_name($name1, $name2, $name3)
    {
        $n1 = ucfirst(strtolower($name1));
        $n2 = ucfirst(strtolower($name2));
        $n3 = ucfirst(strtolower($name3));
        return array($n1, $n2, $n3);
    }
?>
