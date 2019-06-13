'use strict';

{
    let i = 0;
    const showTime = () => {
        console.log(new Date());
        i++;
        if(i > 5) {
            clearInterval(timerId);
        }
    };

    let timerId = setInterval(showTime, 1000);
    setTimeout(showTime, 1000);
}
