'use strict';

{
    const a = [1, 2, 5, 10];

    const b = a.map(item => item*2);
    console.log(b);

    const c = a.filter(item => item%2 === 0);
    console.log(c);
}
