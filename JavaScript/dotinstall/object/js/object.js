'use strict';

{
    const o = {
        a: 1,
        b: 2,
        c: 'char',
    };

    console.log(Object.keys(o));
    console.log(Object.values(o));
    console.log(Object.entries(o));

    Object.keys(o).forEach(key => {
        console.log(`${key} : ${o[key]}`);
    });
}
