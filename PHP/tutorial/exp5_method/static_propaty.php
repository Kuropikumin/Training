<?php
    $test = new Test;

    echo "Test A : " . Test::$static_property;
    echo "Test B : " . $test->get_sp();
    echo "Test C : " . $test->static_property;

    class Test
    {
        static $static_property = "I'm static!\n";
        function get_sp()
        {
            return self::$static_property;
        }
    }
?>
