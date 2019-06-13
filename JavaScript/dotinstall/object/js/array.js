'use strict';

{
    const a = [1, 5, 10];

    for(let i = 0; i < a.length; i++) {
        console.log(i + " : " + a[i]);
    }

    a.forEach((item, index) => {
        console.log(`${index} : ${item}`);
    });

}
