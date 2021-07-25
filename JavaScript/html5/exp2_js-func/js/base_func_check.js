// InternetExplorer か、それ以外のブラウザかのチェック
console.log( "window.navigator.userAgent.toLowerCase().indexOf( \"trident\" ) = " + window.navigator.userAgent.toLowerCase().indexOf( "trident" ) );

// window.console が利用できるブラウザかの確認
if( !window.console === 'undefined' ) {
    console.log( "console関数が利用可能なブラウザです" );
}

// ブラウザの横幅を取得する際のパラメータ
console.log( "window.innerWidth = " + window.innerWidth );
console.log( "document.body.clientWidth = " + ( document.body ? document.body.clientWidth : false ) );
console.log( "document.documentElement.clientWidth = " + document.documentElement.clientWidth );

// ブラウザの縦幅を取得する際のパラメータ
console.log( "window.innerHeight = " + window.innerHeight );
console.log( "document.body.clientHeight = " + ( document.body ? document.body.clientHeight : false ) );
console.log( "document.documentElement.clientHeight = " + document.documentElement.clientHeight );

// アニメーションの実行と停止パラメータ
console.log( "window.requestAnimationFrame = " + window.requestAnimationFrame );
console.log( "window.webkitRequestAnimationFrame = " + window.webkitRequestAnimationFrame );
console.log( "window.mozRequestAnimationFrame = " + window.mozRequestAnimationFrame );
console.log( "window.oRequestAnimationFrame = " + window.oRequestAnimationFrame );
console.log( "window.msRequestAnimationFrame = " + window.msRequestAnimationFrame );

console.log( "window.cancelAnimationFrame = " + window.cancelAnimationFrame );
console.log( "window.webkitCancelRequestAnimationFrame = " + window.webkitCancelRequestAnimationFrame );
console.log( "window.mozCancelRequestAnimationFrame = " + window.mozCancelRequestAnimationFrame );
console.log( "window.oCancelRequestAnimationFrame = " + window.oCancelRequestAnimationFrame );
console.log( "window.msCancelRequestAnimationFrame = " + window.msCancelRequestAnimationFrame );

// 時間の取得
console.log( "window.performance = " + window.performance );
console.log( "performance.now = " + performance.now );
console.log( "performance.mozNow = " + performance.mozNow );
console.log( "performance.msNow = " + performance.msNow );
console.log( "performance.oNow = " + performance.oNow );
console.log( "performance.webkitNow = " + performance.webkitNow );
console.log( "window.performance && performance.now = " );

console.log( "Date.getTime() = " + new Date().getTime() );

// 浮動小数点を整数に変更する
console.log( "10/3 = " + 10/3 );
console.log( "window.I( 10/3 ) = " + window.I( 10/3 ) );


