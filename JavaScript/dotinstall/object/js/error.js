'use strict';

{
    const a = 'hello';
    const b = 10;

    try {
        console.log(a.toUpperCase());
        console.log(b.toUpperCase());
    } catch (e) {
        console.log(e.message);
    }
    console.log('Finish');
}
