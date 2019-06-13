var cnvs   = $('<canvas width = 300 height = 300>').appendTo("body").get(0);
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;

cntxt.beginPath();
cntxt.arc(width/2, height/2, width*0.45, 0, Math.PI*2, false);
cntxt.clip();

cntxt.fillStyle = "#0f0f0f";
cntxt.fillRect(width*0.1, height*0.1, width*0.8, height*0.8);
