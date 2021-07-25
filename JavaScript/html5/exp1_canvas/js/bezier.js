var cnvs   = $('<canvas width = 300 height = 300>').appendTo("body").get(0);
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;

cntxt.beginPath();
cntxt.moveTo(width*0.1, height*0.1);
cntxt.lineTo(width*0.1, height*0.9);
cntxt.lineTo(width*0.9, height*0.9);
cntxt.strokeStyle = "#00f00f";
cntxt.stroke();

cntxt.beginPath();
cntxt.moveTo(width*0.1, height*0.1);
cntxt.quadraticCurveTo(width*0.1, height*0.9, width*0.9, height*0.9);
cntxt.strokeStyle = "#000000";
cntxt.stroke();

