<?php
    $test = 'name';
    $user1 = new User;
    $user1->name     = "hoge";
    $user1->password = "test";
    print_r($user1);

    $user2 = new User;
    $user2->$test    = "fuga";
    $user2->password = "piyo";
    print_r($user2);
    $user2->save_user();

    class User
    {
        public $name, $password;
        function save_user()
        {
            echo "Save User code goes here<br>\n";
        }
    }
?>
