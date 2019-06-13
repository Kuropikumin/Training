var cnvs   = $('<canvas width = 300 height = 300>').appendTo("body").get(0);
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;

cntxt.beginPath();
var r = width*0.1;

cntxt.moveTo(width*0.1, height*0.1);
cntxt.arcTo(width*0.1, height*0.5, width*0.9, height*0.5, r);

cntxt.moveTo(width*0.1, height*0.5);
cntxt.arcTo(width*0.1, height*0.9, width*0.9, height*0.9, r);
cntxt.arcTo(width*0.9, height*0.9, width*0.9, height*0.5, r);
cntxt.lineTo(width*0.1, height*0.5);
cntxt.closePath();

cntxt.strokeStyle = "#ff0000";
cntxt.stroke();
