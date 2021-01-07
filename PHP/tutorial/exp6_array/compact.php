<?php
    $fname   = 'Elizabeth';
    $sname   = 'Windsor';
    $address = 'Buckingham Palace';
    $city    = 'London';
    $country = 'United kingdom';

    $check_value_name = "fname sname address city country";
    $contact = compact( explode( ' ', $check_value_name ) );

    echo "\$check_value_name is > [$check_value_name]<br>\n";

    foreach( $contact as $key => $value ){
        echo "$key : $value <br>\n";
    }
?>
