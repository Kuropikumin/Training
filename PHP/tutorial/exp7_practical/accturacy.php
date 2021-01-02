<?php
    echo "<pre>";
    printf("The result is $%15f",    123.42/12);
    echo  " : \$%15f<br>\n";
    printf("The result is $%015f",   123.42/12);
    echo  " : \$%015f<br>\n";
    printf("The result is $%15.2f",  123.42/12);
    echo  " : \$%15.2f<br>\n";
    printf("The result is $%015.2f", 123.42/12);
    echo  " : \$%015.2f<br>\n";
    printf("The result is $%'#15f",  123.42/12);
    echo  " : \$'#%15f<br>\n";
    printf("The result is $%'>15f",  123.42/12);
    echo  " : \$'>%15f<br>\n";
?>
