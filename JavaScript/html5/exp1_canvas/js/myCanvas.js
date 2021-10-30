var cnvs   = document.getElementById("myCanvas");
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;

cntxt.fillStyle = "#000000";
cntxt.fillRect(0, 0, width, height);

cntxt.fillStyle = "#ff0000";
cntxt.fillRect(width*0.1, height*0.1, width*0.8, height*0.8);
