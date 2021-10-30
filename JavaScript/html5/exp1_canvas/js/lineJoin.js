var cnvs   = $('<canvas width = 300 height = 300>').appendTo("body").get(0);
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;

cntxt.beginPath();
for(var i = 0; i < 3; i++) {
    cntxt.moveTo(width*0.3*i, 0);
    cntxt.lineTo(width*0.3*i, height);
}
cntxt.strokeStyle = "#ccffff";
cntxt.stroke();

cntxt.lineWidth = width*0.1;
cntxt.strokeStyle = "#dd00dd";

for(var i = 0; i < 3; i++) {
    if (i == 0) cntxt.lineJoin = "bevel";
    if (i == 1) cntxt.lineJoin = "round";
    if (i == 2) cntxt.lineJoin = "miter";

    cntxt.beginPath();
    cntxt.moveTo(width*0.3*i,       height*0.2);
    cntxt.lineTo(width*0.3*(i + 1), height*0.5);
    cntxt.lineTo(width*0.3*i,       height*0.8);
    cntxt.stroke();
}
