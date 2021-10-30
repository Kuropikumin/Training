var cnvs   = $('<canvas width = 400 height = 400>').appendTo("body").get(0);
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;

cntxt.fillStyle = "#00ff00";
cntxt.fillRect(0, 0, width, height);

cntxt.fillStyle = "#0000ff";
cntxt.fillRect(width*0.1, height*0.1, width*0.8, height*0.8);
