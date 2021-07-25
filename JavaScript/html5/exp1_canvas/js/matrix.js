var cnvs   = $('<canvas width = 300 height = 300>').appendTo("body").get(0);
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;

cntxt.transform(0, 1, 1, 0, width*0.5, height*0.5);
cntxt.transform(0, 1.2, 0.8, 0, 0, 0);
cntxt.fillStyle = "#ff0000";
cntxt.fillRect(width*-0.4, height*-0.4, width*0.8, height*0.8);

cntxt.transform(0,   0.75, 0.75, 0, 0, 0);
cntxt.transform(0.2, 1, 1, 0.4, 0, 0);
cntxt.fillStyle = "#0000ff";
cntxt.fillRect(width*-0.4, height*-0.4, width*0.8, height*0.8);

cntxt.transform(0.2, 0.5, 0.5, 0.4, width*-0.2, height*0.1);
cntxt.fillStyle = "#00ff00";
cntxt.fillRect(width*-0.4, height*-0.4, width*0.8, height*0.8);
