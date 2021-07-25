var cnvs   = $('<canvas width = 300 height = 300>').appendTo("body").get(0);
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;

cntxt.moveTo(width*0.5, height*0.5);
cntxt.lineTo(width*0.9, height*0.5);
cntxt.lineTo(width*0.5, height*0.9);
cntxt.closePath();

cntxt.fillStyle = "#fff0ff";
cntxt.fill();
