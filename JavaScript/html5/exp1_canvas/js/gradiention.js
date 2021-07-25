var cnvs   = $('<canvas width = 300 height = 300>').appendTo("body").get(0);
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;

var grad = cntxt.createLinearGradient(
    width*0.1,
    height*0.1,
    width*0.4,
    height*0.9);
grad.addColorStop(0,   "#ff0000");
grad.addColorStop(0.5, "#00ff00");
grad.addColorStop(1,   "#0000ff");
cntxt.fillStyle = grad;
cntxt.fillRect(0, 0, width*0.5, height);

var grad = cntxt.createRadialGradient(
    width*0.7,
    height*0.5,
    width*0.1,
    width*0.8,
    height*0.5,
    height*0.5);
grad.addColorStop(0,   "#ff0000");
grad.addColorStop(0.5, "#00ff00");
grad.addColorStop(1,   "#0000ff");
cntxt.fillStyle = grad;
cntxt.fillRect(width*0.5, 0, width, height);
