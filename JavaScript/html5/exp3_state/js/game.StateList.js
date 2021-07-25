game.StateList = function() {
    // 変数
    this.stateList = {};
    this.firstName = null;

    // 追加
    this.add = function( state ) {
        var name = state.name;
        this.stateList[name] = state;
        if( this.firstName == null ) this.firstName = name;
    }

    // リスト取得
    this.getList = function() {
        return this.stateList;
    }

    // 開始状態の取得
    this.getFirstName = function() {
        return this.firstName;
    }
}
