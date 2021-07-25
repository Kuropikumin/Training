// indexOf( "trident" ) の値が 0以上ならInternetExplorer
// -1 だとそれ以外のブラウザ
var ua = window.navigator.userAgent.toLowerCase();
// console.log( "ua.indexOf = " + ua.indexOf("trident") );

// console.log が利用できないブラウザのための関数
if( typeof window.console === 'undefined' ) {
    window.console = new function() {
        this.log   = function() {}
        this.error = function() {}
    }
}

// ウィンドウ横幅サイズの取得
window.getWinW = function() {
    return window.innerWidth ||
           ( document.body ? document.body.clientWidth : false ) ||
           document.documentElement.clientWidth;
}

// ウィンドウ縦幅サイズの取得
window.getWinH = function() {
    return window.innerHeight ||
           ( document.body ? document.body.clientHeight : false ) ||
           document.documentElement.clientHeight;
}

// アニメーションの実行と停止
window.requestAnimFrame =
    window.requestAnimationFrame       ||
    window.webkitRequestAnimationFrame ||
    window.mozRequestAnimationFrame    ||
    window.oRequestAnimationFrame      ||
    window.msRequestAnimationFrame     ||
    // callback: コールバック関数
    // element:  DOM Element
    function( callback, element ) {
        return window.setTimeout( callback, 1000/60 );
    };

window.cancelAnimationFrame =
    window.cancelAnimationFrame              ||
    window.webkitCancelRequestAnimationFrame ||
    window.mozCancelRequestAnimationFrame    ||
    window.oCancelRequestAnimationFrame      ||
    window.msCancelRequestAnimationFrame     ||
    function( id ) {
        clearTimeout( id );
    };

// 時間の取得
var now = window.performance && (
    performance.now    ||
    performance.mozNow ||
    performance.msNow  ||
    performance.oNow   ||
    performance.webkitNow
);

window.getTime = function() {
    return ( now && now.call( performance ) ) ||
           ( new Date().getTime() );
}

window.I = function( i ) {
    return i|0;
    // return parseInt( i, 10 );
}

// 範囲内に存在するかの判定
window.inRng = function( rct, pos ) {
    if( pos.x < rct.x || rct.x + rct.w <= pos.x ||
        pos.y < rct.y || rct.y + rct.h <= pos.y )  {
        return false;
    }
    return true;
}

// 距離の比較
window.compareDist = function( target, source ) {
    var dist_target = Math.pow( target.x, 2 ) + Math.pow( target.y, 2 );
    var dist_source = Math.pow( source.x, 2 ) + Math.pow( source.y, 2 );
    if( dist_target > dist_source ) return true;
    else                            return false;
}

// 距離の計算
window.dstnc = function( x0, y0, x1, y1 ) {
    return Math.sqrt( Math.pow( x0 - x1, 2 ) + Math.pow( y0 - y1, 2 ) );
}

// 数字を範囲内に収める
window.numRng = function( min, max, n ) {
    if( n < min )      return min;
    else if( max < n ) return max;
    else               return n;
}

// 文字列のバイト数を計算する
window.getByteLen = function( s ) {
    s = "" + s;
    var len = 0;

    for( var i = 0; i < s.length; i++ ) {
        var code = s.charCodeAt( i );
        if( code > 255 ) len++;
        len++;
    }
    return len;
}

// 配列の初期化関数
window.bryArr = function( arr, len, p ) {
    for( var i = 0; i < len; i++ ) arr[i] = p;
    return arr;
}

window.initArr = function( len, p ) {
    return this.bryArr( [], len, p );
}

// シード指定可能ランダムオブジェクト
var Xors = function( n ) {
    var x, y, z, w;

    // シード
    this.seed = function( n ) {
        x = 123456789;
        y = 362436069;
        z = 521288629;
        w = 88675123;
        if( typeof n === "number" ) w = n;
    }

    // ランダム
    this.rnd = function() {
        var t;
        t = x^( x << 11 );
        x = y;
        y = z;
        z = w;
        return w = ( w^( w>>19 ) )^( t^( t>>8 ) );
    }

    // 初回実行
    this.seed( n );
}

// 外部HTMLの取得
jQuery.fn.outerHTML = function( s ) {
    if( s ) {
        this.before( s ).remove();
        return this;
    }
    else {
        var dmy = $( "<p>" ).append( this.eq(0).clone() );
        var html = dmy.html();
        dmy.remove();
        return html;
    }
}
