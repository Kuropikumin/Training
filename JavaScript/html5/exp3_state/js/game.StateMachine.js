game.StateMachine = function() {
    // 変数
    // 状態管理
    this.states             = null;
    this.currentState       = null;
    this.nextState          = null;
    this.currentStateName   = null;
    this.nextStateName      = null;
    this.phase              = null; // enter, exec, leave
    this.waitState          = true;

    // イベント管理
    this.acceptEvent = true; // イベント入力可否

    // タップ位置表示
    this.timeListClick = Number.NEGATIVE_INFINITY;
    this.timeListCheck = 0;
    this.tapDrawR      = 6; // タップ描画半径
    this.tapDrawLW     = 6; // タップ描画線幅

    // 構築子
    this.constructor = function( opt ) {
        // 変数の初期化
        var $SP = game.$SP; // システムパラメータ

        // 状態管理の初期化
        this.states = opt.states;

        // 入力イベント用変数の初期化
        var layerTopId = $SP.layerTap.canvasId;
        var $this      = this;

        // 入力イベントの登録
        tappable( "#" + layerTopId, {
            noScroll: true,
            onStart:  function( e, target ) {
                var $SP = game.$SP; // システムパラメータ

                // 操作座標の取得
                var param = {};
                // PC系
                if( typeof e.touches === "undefined" ) {
                    param.x = e.clientX;
                    param.y = e.clientY;
                }
                else {
                    param.x = e.changedTouches[0].pageX;
                    param.y = e.changedTouches[0].pageY;
                }

                // 比率で書き換え
                // Androidのバグでズームを行った場合
                if( $SP.isAndroidBugZoom != null ) {
                    param.x -= $SP.canvasX;
                    param.y -= $SP.canvasY;
                    param.x = param.x/$SP.isAndroidBugZoom;
                    param.y = param.y/$SP.isAndroidBugZoom;
                }
                else {
                    // IEの場合
                    if( window.isMSIE ) {
                        param.x = param.x/document.body.style.zoom;
                        param.y = param.y/document.body.style.zoom;
                        param.x -= $SP.canvasX/document.body.style.zoom;
                        param.y -= $SP.canvasY/document.body.style.zoom;
                    }
                    // IE以外
                    else {
                        param.x = param.x*$SP.winH/getWinH();
                        param.y = param.y*$SP.winH/getWinH();
                        param.x -= $SP.canvasX;
                        param.y -= $SP.canvasY;
                    }
                }

                $this.tap( $this, param, target );
            }
        });

        // 状態管理
        this.transition( opt.currentState || null );
    }

    this.transition = function( nextStateName ) {
        // 初回
        if( this.currentState == null ) {
            this.currentState     = this.states[nextStateName];
            this.currentStateName = nextStateName;
            this.phase            = "preEnter";
        }
        // 2回目以降
        else {
            this.nextState     = this.states[nextStateName];
            this.nextStateName = nextStateName;
            this.phase         = "leave";
        }
    }

    this.render = function() {
        this.fadeTap(); // タップ位置のフェードアウト

        // 変数の初期化
        var $UP   = game.$UP;          // ユーザパラメータ
        var state = this.currentState;
        var phase = this.phase;

        // 時間の有効確認
        if( !$UP.timeEnable ) return;
        game.time.update( "render" ); // 時間の更新

        // フェーズによる分岐
        if     ( phase == "enter" ) state.renderEnter();
        else if( phase == "exec" )  state.renderExec();
        else if( phase == "leave" ) state.renderLeave();
    }

    this.update = function() {
        // 時間の更新
        game.time.update( "update" );

        // フェーズによる分岐
        var next;       // フェーズ遷移フラグ
        var updates = {
            { name: "preEnter", func: "updatePreEnter" },
            { name: "enter",    func: "updateEnter" },
            { name: "preExec",  func: "updatePreExec" },
            { name: "exec",     func: "updateExec" },
            { name: "leave",    func: "updateLeave" }
        };

        for( var i = 0; i < updates.length; i++ ) {
            if( this.phase != updates[i].name ) continue;
            if( next = this.currentState[updates[i].func]() ) {
                this.phase = updates[( i + 1 )%updates.length].name;
                break;
            }
        }

        // シーン遷移がある場合の処理
        if( next ) {
            // フェーズ内の時間リセット
            game.time.reset( "phase" );

            // 入室前時の処理
            if( this.phase == "preEnter" ) {
                this.currentState     = this.nextState;
                this.currentStateName = this.nextStateName
                this.nextState        = null;
            }

            // 入室時の処理
            if( this.phase == "enter" ) this.currentState.enter();

            // 実行時の処理
            if( this.phase == "exec" ) this.currentState.exec();
        }
    }

    this.tap = function( $this, e, target ) {
        // ダイアログの受け入れ確認
        // ダイアログの場合
        if( game.Dialog.enable ) game.Dialog.tap( e );
        // 通常時の処理
        else {
            // 実行有効確認
            if( $this.waitState == true )   return;
            if( $this.phase     != "exec" ) return;
            if( !$this.acceptEvent )        return;

            // 時間の有効確認
            var $UP = game.$UP; // ユーザパラメータ
            if( !$UP.timeEnable ) return;

            // イベントの格納
            var eventParam = { type: "tap", x: e.x, y: e.y };

            // イベントの実行
            this.currentState.actItemEvent( eventParam );
        }

        // タップ位置描画
        this.drawTap( e );
    }

    this.drawTap = function( e ) {
        // 変数の初期化
        var $SP     = game.$SP;           // システムパラメータ
        var context = $SP.layerTap.context;

        // タップ位置描画
        context.beginPath();
        context.arc( e.x, e.y, this.tapDrawR, 0, Math.PI*2, false );

        context.strokeStyle = "#ff0000";
        context.lineWidth   = this.tapDrawLW;
        context.stroke();

        context.fillStyle = "#ffffff";
        context.fill();

        // 時間の記録
        this.timeListClick = getTime();
    }

    this.fadeTap = function() {
        // 変数の初期化
        var $SP     = game.$SP; // システムパラメータ
        var context = $SP.layerTap.context;
        var now     = getTime();
        var elps    = now - this.timeListCheck;

        // 高速環境
        if( !game.utl.checkRowSpeed() ) {
            if( now <= this.timeListClick + 1500 ) {
                // 徐々に消していく
                context.save();
                context.globalAlpha              = numRng( 0, 1 - Math.pow( 0.1, elps/1000 ), 1 );
                context.globalCompositeOperation = "destination-out";
                context.fillStyle                = "black";
                context.fillRect( 0, 0, $SP.canvasW, $SP.canvasH );
                context.restore();
            }
            else {
                if( this.timeListClick != Number.NEGATIVE_INFINITY ) {
                    // 完全に消す
                    game.utl.clearContext( context );
                    this.timeListClick = Number.NEGATIVE_INFINITY;
                }
            }
        }
        // 低速環境
        else {
            if( now > this.timeListClick + 750 &&
                this.timeListClick != Number.NEGATIVE_INFINITY ) {
                // 完全に消す
                game.utl.clearContext( context );
                this.timeListClick = Number.NEGATIVE_INFINITY;
            }
        }

        this.timeListCheck = now;
    }

    // 構築開始
    this.constructor.apply( this, arguments );
};
