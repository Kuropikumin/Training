const WIN_WIDTH  = 700;
const WIN_HEIGHT = 420;
const BLOCK_SIZE = 50;
const BLOCK_NUM  = 8;

class Field {
  constructor() {
    this.tiles = [
      [0, 0, 0, 0, 0, 0, 0, 0],
      [0, 0, 0, 0, 0, 0, 0, 0],
      [0, 0, 0, 0, 0, 0, 0, 0],
      [0, 0, 0, 1, -1, 0, 0, 0],
      [0, 0, 0, -1, 1, 0, 0, 0],
      [0, 0, 0, 0, 0, 0, 0, 0],
      [0, 0, 0, 0, 0, 0, 0, 0],
      [0, 0, 0, 0, 0, 0, 0, 0]
    ];
  }
  tileAt( x, y ) {
    return this.tiles[y][x];
  }
  draw() {
    let r = BLOCK_SIZE/2;
    for( let y = 0; y < BLOCK_NUM; y++ ) {
      for( let x = 0; x < BLOCK_NUM; x++ ) {
        let turn = this.tileAt( x, y );
        switch( turn ) {
          case 0:  noFill();        break;
          case -1: fill( "white" ); break;
          case 1:  fill( "black" ); break;
        }
        circle( BLOCK_SIZE*x + r, BLOCK_SIZE*y + r, BLOCK_SIZE );
      }
    }
  }
  rayToCoords( x, y, dx, dy ) {
    let areaCountains = ( x, y ) => {
      return ( ( 0 <= x && x < BLOCK_NUM ) && ( 0 <= y && y < BLOCK_NUM ) )
    }
    let coords = [];
    while( areaCountains( x, y ) ) {
      coords.push( [x, y] );
      x += dx;
      y += dy;
    }
    return coords;
  }
  coordsToDisks( coords ) {
    return coords.map( p => this.tiles[p[1]][p[0]] );
  }
  flipNum( turn, list ) {
    for( let i = 1; i < list.length; i++ ) {
      // 確認先が空白がある場合
      if( list[i] === 0 ) return 0;
      // 確認先が自分の駒がある場合
      else if( list[i] === turn ) return i - 1;
    }
    // チェック先がすべて相手の駒である場合
    return 0;
  }
  diskNum( turn ) {
    let count = 0;
    for( let y = 0; y < BLOCK_NUM; y++ ) {
      for( let x = 0; x < BLOCK_NUM; x++ ) {
        if( this.tileAt( x, y ) === turn ) count += 1;
      }
    }
    return count;
  }
  diskFlip( x, y, turn ) {
    [0, 1, 2, 3, 4, 5, 6, 7].forEach( d => {
      let [ dx, dy ] = [round( cos( d*PI/4 ) ), round( sin( d*PI/4 ) ) ];
      let flip_num = this.flipNum( turn, this.coordsToDisks( this.rayToCoords( x, y, dx, dy ) ) );
      for( let i = 1; i <= flip_num; i++ ) {
        this.tiles[y + i*dy][x + i*dx] *= -1;
      }
    });
  }
  isPlaseable( x, y, turn ) {
    let total_flip_num = 0;
    if( this.tileAt( x, y ) !== 0 ) return false;

    // 8方向でひっくり返すことができる枚数を計算する
    [0, 1, 2, 3, 4, 5, 6, 7].forEach( d => {
      let [ dx, dy ] = [round( cos( d*PI/4 ) ), round( sin( d*PI/4 ) ) ];
      let flip_num = this.flipNum( turn, this.coordsToDisks( this.rayToCoords( x, y, dx, dy ) ) );
      total_flip_num += flip_num;
    });
    return ( total_flip_num !== 0 );
  }
  isTotalPlaseable( turn ) {
    for( let y = 0; y < BLOCK_NUM; y++ ) {
      for( let x = 0; x < BLOCK_NUM; x++ ) {
        if( this.isPlaseable( x, y, turn ) ) return true;
      }
    }

    return false;
  }
}

class Game {
  constructor() {
    this.field  = new Field();
    this.p1_num = this.field.diskNum( 1 );
    this.p2_num = this.field.diskNum( -1 );
    this.turn   = 1;
    this.part   = "process";
    this.skip_num = 0;
  }
  init() {
    this.field  = new Field();
    this.p1_num = this.field.diskNum( 1 );
    this.p2_num = this.field.diskNum( -1 );
    this.turn   = 1;
  }
  proc() {
    background( "green" );
    this.field.draw();
    switch( this.part ){
      case "process":
        let flag = this.field.isTotalPlaseable( this.turn );
        if( flag ) {
          fill( 0 );
          textSize( 30 );
          text( "黒の得点：" + this.p1_num, BLOCK_SIZE*BLOCK_NUM + 20, 100 );
          text( "白の得点：" + this.p2_num, BLOCK_SIZE*BLOCK_NUM + 20, 300 );
          let turn = ( game.turn === 1 ) ? "黒" : "白";
          text( turn + "の番です", BLOCK_SIZE*BLOCK_NUM + 20, 200 );
          console.log( flag );
        }
        else {
          this.turn *= -1;
          this.skip_num += 1;
          if( this.skip_num == 2 ) this.part = "result";
        }
        break;
      case "result":
        fill( 0 );
        textSize( 30 );
        text( "黒の得点：" + this.p1_num, BLOCK_SIZE*BLOCK_NUM + 20, 100 );
        text( "白の得点：" + this.p2_num, BLOCK_SIZE*BLOCK_NUM + 20, 300 );
        let result = "";
        if( this.p1_num === this.p2_num )    result = "引き分けです";
        else if( this.p1_num > this.p2_num ) result = "黒の勝ちです";
        else                                 result = "白の勝ちです";
        text( result, BLOCK_SIZE*BLOCK_NUM + 20, 200 );
        break;
    }
    
  }
  putDisk( x, y ) {
    this.field.tiles[y][x] = this.turn;
    this.field.diskFlip( x, y, this.turn );
    this.p1_num = this.field.diskNum( 1 );
    this.p2_num = this.field.diskNum( -1 );
    this.turn *= -1;
    this.skip_num = 0;
  }
}