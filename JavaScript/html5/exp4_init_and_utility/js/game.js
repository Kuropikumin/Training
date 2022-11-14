// 初期化時に最低限必要なパラメータは以下の通り
// param.wrapId  - ゲームを挿入するDOM要素のID
// param.winW    - ゲームウインドウ横幅
// param.winH    - ゲームウィンドウ縦幅
// param.layerNo - 使用するレイヤー数
game.initParam = function( param ) {
    // 変数の初期化
    param = cmb( {}, param );
    var $SP = game.$SP = {}; // システムパラメータ
    var $UP = game.$UP = {}; // ユーザパラメータ

    // システムパラメータの初期化
    // 基本
    $SP.wrapId  = param.wrapId; // キャンバスをラップするDOM要素のID
    $SP.winW    = param.winW;   // ウィンドウ横幅
    $SP.winH    = param.winH;   // ウィンドウ縦幅
    $SP.canvasW = param.winW;   // キャンバス横幅
    $SP.canvasH = param.winH;   // キャンバス縦幅
    $SP.canvasX = 0;
    $SP.canvasY = 0;
    $SP.device  = "unknown";    // デバイス

    // PCアプリ関係
    $SP.isNW    = !!window.require; // node-webkit使用しているか
    $SP.isPcAPP = $SP.isNW;         // PCアプリかどうか

    // Androidアプリ関係
    $SP.isAndroidApp = ( typeof window.android !== "undefined" ); // Androidアプリかどうか
    $SP.isAndroidBugZoom = null;                                  // Androidのバグでズームをしないといけないか

    // レイヤー関係
    $SP.layerNo       = param.layerNo;     // レイヤー数
    $SP.layerTop      = param.layerNo - 1; // 最上位レイヤー
    $SP.layers        = [];                // レイヤー配列
    $SP.layerDialog   = null;              // レイヤーダイアログ
    $SP.layerDebug    = null;              // レイヤーデバッグ
    $SP.layerTap      = null;              // レイヤータップ
    $SP.layerObjectAll = [];                // レイヤーjQueryオブジェクト配列
                                           // ダイアログ、デバッグ、タップすべて

    // ユーザパラメータの初期化
    $UP.timeEnable = false;                        // 時間有効有無
    $UP.time       = { whole: null, phase: null }; // 時間
    $UP.dataId     = "";                           // データ入出力用のID
                                                   // ゲーム固有の処理の中で、ゲーム名を書き込む
                                                   // ほかのゲームのデータを読み込まないようにするためのフラグ
    $UP.ex         = {};                           // ゲーム外のデータ 主に入出力用
    $UP.gameData   = null;                         // ゲームデータ
    $UP.gameOption = {                             // ゲームオプション
                         gameMode: null,           // ゲームモード
                         difficult: 0              // 難易度
                     };
    $UP.sound = {                                  // サウンド
                    volumeBgm: 100,                // BGM音量
                    volumeSe:  100,                // SE音量
                };    
}

game.init = function( param ) {
    // パラメータの初期化
    game.initParam( param ); // パラメータの初期化
    var $SP = game.$SP;      // システムパラメータ

    // 画面サイズの設定
    // ウィンドウ横幅の調整
    //   横長の場合は縦位置を基準に横を拡大する
    var wStart = getWinW();
    var hStart = getWinH();

    if( wStart/hStart > $SP.winW/$SP.winH ) {
        $SP.winW = wStart/hStart*$SP.winH;
        if( I( $SP.winW ) != $SP.winW ) { 
            $SP.winW = I( $SP.winW ) + 1; // 端数がある場合は +1
         }
    }

    // ビューポートの設定
    monaca.viewport( {
        width:        $SP.winW,
        onAdjustment: function( ratio ) {
            if( window.isMSIE ) {
                $( "[style*=position]" ).each( function () {
                    $(this).css( "zoom", ratio );
                })
            }
        }
    });

    // 縦の調整とキャンバスの位置補正
    game.adjustWinCanvas();

    // デバイスの取得
    if( monaca.viewport.isIos() )       $SP.device = "iOS";
    if( monaca.viewport.isAndroid() )   $SP.device = "Android";
    if( monaca.viewport.isPCBrowser() ) $SP.device = "PC";
}

game.calcWinH = function() {
    var $SP = game.$SP; // システムパラメータ
    return I( $SP.winW*getWinH()/getWinW() );
}

game.adjustWinCanvas = function() {
    var $SP = game.$SP; // システムパラメータ

    // 縦を調整
    $SP.winH = game.calcWinH();

    // キャンバスの位置補正
    if( $SP.winW > $SP.canvasW ) $SP.canvasX = I( ( $SP.winW - $SP.canvasW )/2 );
    if( $SP.winH > $SP.canvasH ) $SP.canvasY = I( ( $SP.winH - $SP.canvasH )/2 );
}

game.adjustWinCanvasForAndroidBugZoom = function() {
    var $SP  = game.$SP;  // システムパラメータ
    $SP.winH = getWinH(); // 縦を調整

    // キャンバスの位置補正
    $SP.canvasX = I( ( $SP.winW = $SP.canvasW*$SP.isAndroidBugZoom )/2 );
    $SP.canvasY = I( ( $SP.winH = $SP.canvasH*$SP.isAndroidBugZoom )/2 );
}

game.initAfterReady = function() {
    // 変数の初期化
    var $SP = game.$SP; // システムパラメータ

    // スクロール禁止
    if( $SP.device == "PC" ) {
        // PCの場合はオーバーフローを隠す（IE対策）
        $( "body" ).css( "overflow", "hidden" );
    }
    else {
        // スマフォの場合はスクロール処理を禁止する
        $( window ).on( "touchmove.noScroll", function( e ) {
            e.preventDefault();
        });
    }

    // IEの場合の補正
    if( window.isMSIE ) {
        $SP.canvasX = I( $SP.canvasX*$( document ).height()/$SP.winH );
        $SP.canvasY = I( $SP.canvasY*$( document ).height()/$SP.winH );
    }

    // アドレスバーを隠す処理
    if( $SP.device != "PC" ) {
        // スクロール可能にするためのダミー要素を挿入
        $( "body" ).append(
            $( "<div>" ).html( "&nbsp;" ).css( "position", "absolute" ).css( "zIndex", -1 ).css( "opacity", 0 ).height( $( window ).height()*2 )
        );

        // 遅延させて隠す
        setTimeout( function() {
            scrollTo( 0, 1 ); // 隠す
            scrollTo( 0, 0 ); // 隠す
        }, 100 );
    }

    var reCalcWinSize = function() {
        // 高さが変わっている場合、もしくはAndroid2.3のバグが発生した場合再計算処理を実施
        if( $SP.winH != game.calcWinH() || $SP.canvasX == infinity ) {
            // Android2.3のバグの場合の処理
            if( ( $SP.device == "Android" && $SP.canvasX == infinity ) || $SP.isAndroidBugZoom != null ) {
                $SP.winW = getWinW();

                // canvasのズーム率を設定（Android2.3 のバグ時のみの仕様）
                $SP.isAndroidBugZoom = $SP.winW/$SP.canvasW;

                // canvasのサイズを変える
                //   bodyをズームしても反映されないので、直接canvasを操作
                for( var i = 0; i < $SP.layerObjectAll.length; i++ ) {
                    $SP.layerObjectAll[i].css( "zoom", $SP.winW/$SP.canvasW );
                }

                // 縦の調整とキャンバスの位置補正（Android2.3バグ版）
                game.adjustWinCanvasForAndroidBugZoom();
            }
        }
        // 通常時
        else {
            game.adjustWinCanvas(); // 縦とキャンバスの位置調整
        }

        // canvas位置を反映
        for( var i = 0; i < $SP.layerObjectAll.length; i++ ) {
            $SP.layerObjectAll[i].css( "left", $SP.canvasX ).css( "top", $SP.canvasY );
        }
    }
}

game.layer.init = function() {
    // 変数の初期化
    var $SP = game.$SP; // システムパラメータ

    // ラップ要素の位置をrelativeに
    $( "#" + $SP.wrapId ).attr( "position", "relative" );

    // レイヤーの初期化
    $SP.layers = [];
    for( var i = 0; i < $SP.layerNo; i++ ) {
        // レイヤーの作成
        $SP.layers.push( this.makeLayer( $SP.wrapId + "_canvas_" + i ) );
        $SP.layerObjectAll.push( $( "#" + $SP.layers[i].canvasId ) );
    }

    // ダイアログ表示レイヤーの初期化
    $SP.layerDialog = this.makeLayer( "canvasDialog" );
    $SP.layerObjectAll.push( $( "#" + $SP.layerDialog.canvasId ) );

    // デバッグ表示レイヤーの初期化
    $SP.layerDebug = this.makeLayer( "canvasDebug" );
    $SP.layerObjectAll.push( $( "#" + $SP.layerDebug.canvasId ) );

    // デバッグ表示レイヤーの初期化
    $SP.layerTap = this.makeLayer( "canvasTap" );
    $SP.layerObjectAll.push( $( "#" + $SP.layerTap.canvasId ) );
}

game.layer.makeLayer = function( canvasId ) {
    // 変数の初期化
    var $SP = game.$SP; // システムパラメータ   

    // キャンバスの初期化
    var canvas = $( '<canvas' +
                      ' width='  + $SP.canvasW         +
                      ' height=' + $SP.canvasH         +
                      ' id="'    + canvasId + '"'      +
                      ' style="position: absolute;'    +
                      ' left: '  + $SP.canvasX + "px;" +
                      ' top: '   + $SP.canvasY + "px;" +
                      ' -webkit-tap-highlight-color: rgba( 0, 0, 0, 0 );' +
                      '">'
                  ).get( 0 );

    $( "#" + $SP.wrapId ).append( canvas );
    var cntxt = canvas.getContext( "2d" );

    // レイヤーハッシュ
    var layer = { canvasId: canvasId, canvas: canvas, cntxt: cntxt };
    return layer;
}

game.time = function() {}

game.time.init = function() {
    // 変数の初期化
    var $SP = game.$SP; // システムパラメータ
    var $UP = game.$UP; // ユーザパラメータ

    // 時間を有効に
    $UP.timeEnable = true;

    // 時間オブジェクト
    var TimeParam = function() {

    }
}