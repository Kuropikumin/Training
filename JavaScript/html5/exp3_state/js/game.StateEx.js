game.StateBase = game.State.extend( {
    name:           "StateBase", // オーバーライドに必要
    transitionTime: 500,         // フェードイン/アウトに使う遷移時間

    // レイヤークリア用変数
    clearDiv:   4,    // クリア時の縦横の画面分割
    clearDiv2:  null, // クリア時の画面分割数の2乗（横4×縦4）
    clearCount: null, // クリア時の処理状態のカウンター

    // 構築子
    constructor: function( opt ) {
        this.base.apply( this, [opt] );

        // レイヤークリア用変数の初期化
        this.clearDiv2  = this.clearDiv*this.clearDiv;
        this.clearCount = this.clearDiv2; // 背景は必ず上書きされるので、背景以降からクリア処理を行う
    },
    renderEnter: function() {
        this.renderExec(); // 実行時のレンダーを背後に描く

        // フェードイン
        var $SP = game.$SP; // システムパラメータ
        game.utl.drawFade( $SP.layerTop, this.transitionTime, "in" );
    },

    renderLeave: function() {
        this.renderExec(); // 実行時のレンダーを背後に描く

        // フェードアウト
        var $SP = game.$SP;
        game.utl.drawFade( $SP.layerTop, this.transitionTime, "out" );
    },

    updatePreEnter: function() {
        // 変数の初期化
        var $SP = game.$SP;
        var clearLayerMax = ( $SP.layerNo - 1 )*this.clearDiv2;

        // 終了条件の確認
        if( this.clearCount < clearLayerMax ) {
            var w2 = I( $SP.canvasW/this.clearDiv );
            var h2 = I( $SP.canvasH/this.clearDiv );
            var opt = {
                x: w2*(    this.clearCount%this.clearDiv2%this.clearDiv ),
                y: h2*( I( this.clearCount%this.clearDiv2/this.clearDiv ) ),
                w: w2,
                h: h2
            };

            // レイヤーのクリア
            game.utl.clearCntxt( I( this.clearCount/this.clearDiv2 ), opt );

            this.clearCount++; // カウントを増加
            return false;
        }
        else {
            if( this.clearCount < clearLayerMax + 2 ) {
                this.clearCount++; // カウントを増加
                return false;
            }
        }
        this.clearCount = 0;
        return true;
    },
    updatePreExec: function() {
        // 変数の初期化
        var $SP = game.$SP; // システムパラメータ

        // レイヤーのクリア
        game.utl.clearCntxt( $SP.layerTop );

        // 終了条件の確認
        if( this.clearCount < 4 ) {
            this.clearCount++; // カウントを増加
            return false;
        }
        this.clearCount = this.clearDiv2;
        return true;
    },
    updateEnter: function() {
        // 変数の初期化
        var $UP  = game.$UP; // ユーザパラメータ
        var elps = $UP.time.phase.update.sum;

        // 遷移時間より長ければ次のフェーズ
        if( elps >= this.transitionTime ) return true;
        return false;
    },
    updateLeave: function() {
        // 変数の初期化
        var $UP = game.$UP; // ユーザパラメータ
        var elps = $UP.time.phase.update.sum;

        // 遷移時間より長ければ次のフェーズ
        if( elps >= this.transitionTime ) return true;
        return false;
    }
});
