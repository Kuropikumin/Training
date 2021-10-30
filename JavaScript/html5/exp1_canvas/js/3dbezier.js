var cnvs   = $('<canvas width = 300 height = 300>').appendTo("body").get(0);
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;

cntxt.beginPath();
cntxt.moveTo(width*0.1, height*0.1);
cntxt.lineTo(width*0.1, height*0.9);
cntxt.moveTo(width*0.9, height*0.9);
cntxt.lineTo(width*0.9, height*0.1);
cntxt.strokeStyle = "#c0c0c0";
cntxt.stroke();

cntxt.beginPath();
cntxt.moveTo(width*0.1, height*0.1);
// cntxt.bezierCurveTo(width*0.1, height*0.9, width*0.9, height*0.1, width*0.9, height*0.9)
// 滑らかではないベジェ曲線
cntxt.bezierCurveTo(width*0.9, height*0.9, width*0.1, height*0.9, width*0.9, height*0.1)
// 弧状の形
// cntxt.bezierCurveTo(width*0.9, height*0.45, width*0.1, height*0.9, width*0.45, height*0.1)
cntxt.strokeStyle = "#000000";
cntxt.stroke();

