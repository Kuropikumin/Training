game.State = base2.Base.extend( {
    // 変数
    name:           "State",               // need override
    items:          [],                    // 描画アイテム配列
    nextState:      null,                  // 次の状態
    constructor:    function( option ) {}, // 構築子
    enter:          function() {           // 入室（1度だけ）
        this.nextState = null; // 次の状態をクリア
        this.items = [];       // 描画アイテム配列を初期化
    },
    exec:           function() {},         // 実行（1度だけ）
    renderEnter:    function() {},
    renderExec:     function() {
        this.actItemRender(); // アイテムのレンダー
    },
    renderLeave:    function() {},
    updatePreEnter: function() {},
    updateEnter:    function() {},
    updatePreExec:  function() {},
    updateExec:     function() {
        this.actItemUpdate();         // 次のシーンのアップデート
        return this.checkNextState(); // 次のシーンを確認
    },
    updateLeave:    function() {},
    checkNextState: function() {
        // 変数の初期化
        var $SP = game.$SP; // システムパラメータ

        // 次のシーンへの移動を確認
        if( this.nextState ) {
            $SP.sm.transition( this.nextState ); // シーンの設定
            return true;                         // 次のシーンへ移動
        }
        return false;                            // シーンを維持
    },
    actItemRender: function() {
        for( var i = 0; i < this.items.length; i++ ) {
            // 途中で次の状態が設定されれば終了
            if( this.nextState != null ) return;

            var item = this.items[i];
            if( item.needRender ) item.render();
        }
    },
    actItemUpdate: function() {
        for( var i = 0; i < this.items.length; i++ ) {
            // 途中で次の状態が設定されれば終了
            if( this.nextState != null ) return;

            var item = this.items[i];
            if( item.needUpdate ) item.update();
        }
    },
    actItemEvent:  function( e ) {
        // 次の状態が設定されていれば処理は実施しない
        if( this.nextState != null ) return;

        // 変数の初期化
        var $SP    = game.$SP; // システムパラメータ
        var layers = $SP.layers;

        // レイヤーの上から順番に判定
        outer: for( var i = layers.length - 1; i >= 0; i-- ) {
            // 確認対象レイヤーの参照を初期化
            var targetContext = layers[i].context;

            // レイヤーに登録されている描画アイテムを走査
            for( var j = 0; j < this.items.length; j++ ) {
                // 変数の初期化
                var item = this.items[j];
                if( !item.accptEvent ) continue; // 受け入れなし

                // 一致するレイヤー以外は無視
                if( item.context != targetContext ) continue;

                // trueを戻せば終了
                if( item.event( e ) ) break outer;
            }
        }
    }
});
