'use strict';

{
    let d = new Date();
    console.log(d);

    console.log(d.getFullYear());
    console.log(d.getMonth());
    console.log(d.getDate());
    console.log(d.getDay());
    console.log(d.getHours());
    console.log(d.getMinutes());
    console.log(d.getSeconds());
    console.log(d.getMilliseconds());
    console.log(d.getTime());
    console.log('------------------------------------------------');

    d = new Date(2019, 1);
    d.setDate(32);

    console.log(d);

    const d2 = new Date(2018, 11, 14);
    console.log(d - d2);
    console.log((d - d2)/(1000*60*60*24));

}
