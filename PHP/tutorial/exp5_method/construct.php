<?php
    $u1 = new User("piyo", "pass");

    echo $u1->get_name() . "<br>\n";
    echo $u1->get_pass() . "<br>\n";

    class User
    {
        private $name, $pass;
        public function __construct($n, $p)
        {
            echo "constract\n";
            $this->name = $n;
            $this->pass = $p;
        }

        function get_name()
        {
            return $this->name;
        }

        function get_pass()
        {
            return $this->pass;
        }
    }
?>
