var cnvs   = $('<canvas width=300 height=300>').appendTo("body").get(0);
var cntxt  = cnvs.getContext("2d");
var width  = cnvs.width;
var height = cnvs.height;
var oprtn = [
        "source-atop",
        "source-in",
        "source-out",
        "source-over",
        "destination-atop",
        "destination-in",
        "destination-out",
        "destination-over",
        "lighter",
        "copy",
        "xor"
    ];

for(var i = 0; i < oprtn.length; i++) {
    // 初期化
    cntxt.clearRect(0, 0, width, height);
    cntxt.globalCompositeOperation = "source-over";

    // 1つ目の図形を描写
    cntxt.fillStyle = "#ff0000";
    cntxt.fillRect(width*0.1, height*0.1, width*0.6, height*0.6);

    // 2つ目の図形を描写するオプションを設定
    cntxt.globalCompositeOperation = oprtn[i];
    // 2つ目の図形を描写
    cntxt.fillStyle = "#00ff00";
    cntxt.fillRect(width*0.3, height*0.3, width*0.6, height*0.6);

    // 図形の範囲をわかりやすくするための枠線を表示
    cntxt.globalCompositeOperation = "source-over";
    cntxt.fillStyle = "#000000";
    cntxt.lineWidth = 3;
    cntxt.strokeRect(width*0.1, height*0.1, width*0.6, height*0.6);
    cntxt.strokeRect(width*0.3, height*0.3, width*0.6, height*0.6);

    var img = new Image();
    img.src = cnvs.toDataURL();
    $("body").append("<br>" + i + " : " + oprtn[i] + "<br>").append(img);
}
// cntxt.clearRect(1, 0, width, height);
cnvs.remove();
