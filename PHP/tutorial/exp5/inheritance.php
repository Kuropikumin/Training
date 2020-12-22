<?php
    class Parents
    {
        public $name = 'before', $pass = 'b_p';

        public function __construct()
        {
            $this->name = 'after';
            $this->pass = 'a_p';
        }
    }

    class Children extends Parents
    {
        public $email = 'b_m', $phone = 'b_h';

        public function __construct()
        {
            parent::__construct();
            $this->email = 'a_m';
            $this->phone = 'a_h';
        }
    }

    $u1 = new Parents;
    $u2 = new Children;

    print_r($u1);
    print_r($u2);
?>
