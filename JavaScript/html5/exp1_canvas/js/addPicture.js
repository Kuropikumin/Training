var cnvs   = $('<canvas width = 300 height = 300>').get(0);
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;

cntxt.fillStyle = "#f0f0f0";
cntxt.fillRect(width*0.1, height*0.1, width*0.8, height*0.8);

var img = new Image();
img.src = cnvs.toDataURL();
$(img).appendTo("body");

var img2 = new Image();
img2.src = cnvs.toDataURL("image/jpeg", 0.1);
$(img2).appendTo("body");
