'use strict';

{
    const a = [10, 20];
    const b = [1, 2, ...a];
    console.log(b);

    a[0] = 100;
    console.log(b);
    
    const sum = (a, b) => a + b;
    console.log(sum(...a));

    const numbers = [1, 2, 3, 8];
    const [c, d, ...rest] = numbers;
    console.log(c);
    console.log(d);
    console.log(rest);

    const player = {
        name:  'taguchi',
        score: 55,
        hp:    33,
        mp:    22,
    }

    const {name, score, ...points} = player;
    console.log(name);
    console.log(score);
    console.log(points);

}
