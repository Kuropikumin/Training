var cnvs   = $('<canvas width = 300 height = 300>').appendTo("body").get(0);
var cntxt  = cnvs.getContext("2d");

// Tangential lines
//cntxt.beginPath();
//cntxt.strokeStyle = 'gray';
//cntxt.moveTo(200, 20);
//cntxt.lineTo(200, 130);
//cntxt.lineTo(50, 20);
//cntxt.stroke();
//
//// Arc
//cntxt.beginPath();
//cntxt.strokeStyle = 'black';
//cntxt.lineWidth = 5;
//cntxt.moveTo( 200, 20);
//cntxt.arcTo( 200, 130, 50, 20, 40);
//cntxt.stroke();
//
//// Start point
//cntxt.beginPath();
//cntxt.fillStyle = 'blue';
//cntxt.arc(200, 20, 5, 0, 2 * Math.PI);
//cntxt.fill();
//
//// Control points
//cntxt.beginPath();
//cntxt.fillStyle = 'red';
//cntxt.arc(200, 130, 5, 0, 2 * Math.PI); // Control point one
//cntxt.arc(50, 20, 5, 0, 2 * Math.PI);   // Control point two
//cntxt.fill();
var width  = cnvs.width;
var height = cnvs.height;

cntxt.beginPath();
var r = width*0.1;

cntxt.moveTo(width*0.1, height*0.1);
cntxt.arcTo(width*0.5, height*0.5, 30, height*0.5, r);
// cntxt.lineTo(width*0.9, height*0.5);

cntxt.moveTo(width*0.1, height*0.5);
cntxt.arcTo(width*0.1, height*0.9, width*0.9, height*0.9, r);
cntxt.arcTo(width*0.9, height*0.9, width*0.9, height*0.5, r);
cntxt.lineTo(width*0.1, height*0.5);
cntxt.closePath();

cntxt.strokeStyle = "#ff0000";
cntxt.stroke();
