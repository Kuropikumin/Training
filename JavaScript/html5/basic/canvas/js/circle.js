var cnvs   = $('<canvas width = 300 height = 300>').appendTo("body").get(0);
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;

cntxt.beginPath();
cntxt.arc(width/3, height/3, width*0.25, 0, Math.PI*1.25, false);

cntxt.moveTo(width*2/3, height*2/3);
cntxt.arc(width*2/3, height*2/3, width*0.25, 0, Math.PI*1.75, false);

cntxt.strokeStyle = "#00ff00";
cntxt.stroke();
