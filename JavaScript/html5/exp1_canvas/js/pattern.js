var cnvs   = $('<canvas width = 300 height = 300>').appendTo("body").get(0);
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;

var img = new Image();
img.onload = function() {
    var pttrn = cntxt.createPattern(img, null);
    cntxt.fillStyle = pttrn;
    cntxt.rect(width*0.1, height*0.1, width*0.6, height*0.6);
    cntxt.rect(width*0.3, height*0.3, width*0.6, height*0.6);
    cntxt.fill();
}

img.src = "png/test.png"
