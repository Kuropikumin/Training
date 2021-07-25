var cnvs   = $('<canvas width = 300 height = 300>').appendTo("body").get(0);
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;

cntxt.fillStyle = "#ffffff";
cntxt.fillRect(0, 0, width, height);

cntxt.fillStyle = "#ff0000";
cntxt.fillRect(width*0.1, height*0.1, width*0.8, height*0.8);
cntxt.lineWidth = 5;
cntxt.strokeRect(width*0.1, height*0.1, width*0.8, height*0.8);

var imgDt = cntxt.getImageData(0, 0, width*0.8, height*0.8);

var sz = (width*0.8);
for(var i = 0; i < sz; i++) {
    var p = (i + i*sz)*4;
    imgDt.data[p + 0] = 0;
    imgDt.data[p + 1] = 0;
    imgDt.data[p + 2] = 255;
}

var cnvs2  = $('<canvas width = 300 height = 300>').appendTo("body").get(0);
var cntxt2 = cnvs2.getContext("2d");

cntxt2.fillStyle = "#ffff00";
cntxt2.fillRect(0, 0, width, height);

cntxt2.putImageData(imgDt, width*0.1, height*0.1);
