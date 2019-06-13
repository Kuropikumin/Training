var cnvs   = $('<canvas width = 300 height = 300>').appendTo("body").get(0);
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;

cntxt.fillStyle = "#fff0ff";
cntxt.lineWidth = 5;

cntxt.beginPath();
cntxt.arc(0, 0, width*0.2, 0, Math.PI*2, false);
cntxt.stroke();

cntxt.save();

cntxt.translate(width*0.5, height*0.5);
cntxt.rotate(Math.PI*0.2);
cntxt.scale(1.5, 2);

cntxt.beginPath();
cntxt.arc(0, 0, width*0.2, 0, Math.PI*2, false);
cntxt.stroke();

cntxt.restore();

cntxt.beginPath();
cntxt.arc(150, 150, width*0.3, 0, Math.PI, false);
cntxt.stroke();
