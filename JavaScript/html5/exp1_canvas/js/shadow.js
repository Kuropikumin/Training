var cnvs   = $('<canvas width = 300 height = 300>').appendTo("body").get(0);
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;

cntxt.shadowColor   = "#0000ff";
cntxt.shadowOffsetX = width*0.1;
cntxt.shadowOffsetY = height*0.2;
cntxt.shadowBlur    = width*0.1;

cntxt.fillStyle = "#ff0000";
cntxt.fillRect(width*0.15, height*0.1, width*0.6, height*0.6);
