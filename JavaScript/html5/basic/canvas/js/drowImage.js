var cnvs   = $('<canvas width = 300 height = 300>').appendTo("body").get(0);
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;

var img = new Image();
img.onload = function() {
    cntxt.drawImage(img, width*0.05, height*0.05, width*0.9, height*0.4);
    cntxt.drawImage(img, width*0, height*0, width*0.3, height*0.3, width*0.05, height*0.55, width*0.9, height*0.9);
}

img.src = "png/map.png";

