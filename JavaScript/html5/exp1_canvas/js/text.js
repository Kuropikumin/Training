var cnvs   = $('<canvas width = 300 height = 300>').appendTo("body").get(0);
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;

var text   = 'abc';
cntxt.font = "36px serif";
var txtW   = cntxt.measureText(text).width;
var txtH   = 36;

cntxt.beginPath();
cntxt.moveTo(width*0.5, height*0);
cntxt.lineTo(width*0.5, height*1);
for(var i = 0; i < 3; i++) {
    cntxt.moveTo(width*0, height*0.2*i);
    cntxt.lineTo(width*1, height*0.2*i);
}

cntxt.strokeStyle = "#00f00f";
cntxt.stroke();

cntxt.fillText(text, width*0.5, height*0.2);
cntxt.strokeRect(width*0.5, height*0.2 - txtH, txtW, txtH);

cntxt.textAlign = "center";
cntxt.textBaseline = "middle";
cntxt.fillText(text, width*0.5, height*0.4);
cntxt.strokeRect(width*0.5 - txtW*0.5, height*0.4 - txtH*0.5, txtW, txtH);

cntxt.strokeText(text, width*0.5, height*0.6, txtW/2);
cntxt.strokeRect(width*0.5 - txtW*0.5, height*0.6 - txtH*0.5, txtW, txtH);

cntxt.textAlign = "right";
cntxt.textBaseline = "top";
cntxt.fillText(text, width*0.5, height*0.8);
cntxt.strokeRect(width*0.5 - txtW, height*0.8, txtW, txtH);

