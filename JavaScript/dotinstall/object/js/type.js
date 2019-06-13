'use strict';

{
    let x = 1;
    let y = x;
    x = 5;

    console.log(x);
    console.log(y);

    let ax = [1, 2];
    let ay = ax;

    ax[0] = 5;

    console.log(ax);
    console.log(ay);
}
