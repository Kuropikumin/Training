game.init({ winW: 640, winH: 640, wrapId: "canvasArea", layerNo: moveBy.layer.size });

$( "document" ).ready( function() {
    // ゲームの初期化
    game.initAfterReady();    // 準備完了後の初期化
    game.layer.init();        // レイヤーの初期化
    game.time.init();         // 時間の初期化
    game.utl.initViewParts(); // 表示設定の初期化
    my.init();                // ゲーム固有情報の初期化

    // ゲームの状態リストの作成
    var state = new game.StateList();
    state.add( new moveBy.StateAuthor() ); // 著者情報
    state.add( new moveBy.StateTitle() );  // タイトル画面

    // ゲームの作成
    var stateMachine = new game.StateMachine({
        sates:        state.getList(),
        currentState: state.getFirstName()
    });

    var engine = new game.Engine( stateMachine );
})

