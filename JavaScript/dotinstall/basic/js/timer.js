var i = 0;

(show = function() {
    console.log(i++);
    var tid = setTimeout(function() {
        show();
    }, 1000);
    if (i > 3) {
        clearTimeout(tid);
    }
})()
