game.Engine = function() {
    // 変数
    this.stateMachine   = null;
    this.updateInterval = 1000/16; // 16fps, 62msecごとにアップデート
    this.renderId       = null;    // レンダーループID。停止に必要
    this.updateId       = null;    // アップデートループID。停止に必要
    var $this           = this;

    // コンストラクタ
    this.constructor = function( stateMachine ) {
        // 状態機械(stateMachine)の格納
        this.stateMachine = stateMachine; // 状態機械の格納
        var $SP           = game.$SP;     // システムパラメータ
        $SP.sm            = stateMachine; // 状態機械の格納

        // 初期化処理
        game.time.init(); // 時間の初期化
        this.start();     // 処理の開始

        // PCアプリでは動きっぱなしにするのでイベント登録しない
        if( $SP.isPCApp ) return;

        window.focus();

        // 待機処理のイベント登録
        if( window == window.top ) {
            // ウィンドウのネストがない場合
            $( window ).focus( function( e ) {
                $this.start.apply( $this ); // フォーカスで開始
            }).blur( function( e ) {
                $this.stop.apply( $this );  // ブラーで停止
            });
        }
        else {
            // ウィンドウがネストしている場合
            // 自ウインドウ
            $( window ).focus( function( e ) {
                $this.start.apply( $this ); // フォーカスで開始
            }).blur( function( e ) {
                $this.stop.apply( $this );  // ブラーで停止
            });

            $( window.top ).focus( function( e ) {
                $this.start.apply( $this ); // フォーカスで開始
            }).blur( function( e ) {
                $this.stop.apply( $this );  // ブラーで停止
            });
        }
    }

    this.start = function() {
        // 重複処理対策
        if( this.stateMachine.waitState == false ) return;

        // 待機中の切り替え
        this.stateMachine.waitState = false;
        game.R.playBgm();

        // ダイアログ中/入出力中でなければタイマー開始
        if( !game.Dialog.enable && !game.IO.enable ) {
            game.time.start();
        }

        // レンダーとアップデートの実行管理
        if( !this.renderId ) {
            this.render();
        }

        if( !this.updateId ) {
            this.updateId = setInterval( this.update, game.Engine.updateInterval );
        }
    }

    this.stop = function() {
        //重複処理対策
        if( this.stateMachine.waitState == true ) return;

        //待機処理の切り替え
        this.stateMachine.waitState = true;
        game.R.pauseBgm(); // BGM停止

        // レンダーとアップデートの実行管理
        if( this.renderId ) {
            cancelAnimationFrame( this.renderId );
            this.renderId = null;
        }
        if( this.updateId ) {
            clearInterval( this.updateId );
            this.updateId = null;
        }
    }

    this.render = function() {
        $this.renderId = requestAnimFrame( $this.render );
        $this.sateMachine.render();
    }

    this.update = function() {
        $this.stateMachine.update();
    }

    //構築開始
    this.constructor.apply( this, arguments );
}


