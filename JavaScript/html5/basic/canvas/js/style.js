var cnvs   = $('<canvas width = 300 height = 300>').appendTo("body").get(0);
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;

cntxt.beginPath();
cntxt.moveTo(width*0.8, 0);
cntxt.lineTo(width*0.8, height);
cntxt.strokeStyle = "#00f00f";
cntxt.stroke();

cntxt.lineWidth   = width*0.1;
cntxt.strokeStyle = "#00ffff";
for(var i = 0; i < 3; i++) {
    if(i == 0) cntxt.lineCap = "butt";
    if(i == 1) cntxt.lineCap = "round";
    if(i == 2) cntxt.lineCap = "square";
    cntxt.beginPath();
    cntxt.moveTo(0, height*(0.3 + i*0.2));
    cntxt.lineTo(width*0.8, height*(0.3 + i*0.2));
    cntxt.stroke();
}
