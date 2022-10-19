const WIN_WIDTH  = 360;
const WIN_HEIGHT = 540;
const BLOCK_SIZE = 30;

class Block {
  constructor( x, y, color = "white" ) {
    this.x = x;
    this.y = y;
    this.color = color;
  }
  draw() {
    push();
    fill( this.color );
    rect( BLOCK_SIZE*this.x, BLOCK_SIZE*this.y, BLOCK_SIZE, BLOCK_SIZE );
    pop();
  }
}

class Mino {
  constructor( x, y, rot, shape ) {
    this.x = x;
    this.y = y;
    this.rot = rot;
    this.shape = shape;
  }
  calcBlocks() {
    let blocks = this.createBlocks();
    let rot = ( 40000000 + this.rot )%4;
    for( let r = 0; r < rot; r++ ) {
      blocks = blocks.map( b => new Block( -b.y, b.x, b.color ) );
    }
    blocks.forEach( b => ( b.x += this.x, b.y += this.y ) );
    return blocks;
  }
  createBlocks() {
    let blocks = [];
    switch( this.shape ) {
      case 0: //T
        blocks = [new Block( -1, 0 ), new Block( 0, 0 ), new Block( 0, -1 ), new Block( 1, 0 )];
        blocks.forEach( b => b.color = "red" );
        break; 
      case 1: //Z
        blocks = [new Block( -1, -1 ), new Block( 0, -1 ), new Block( 0, 0 ), new Block( 1, 0 )];
        blocks.forEach( b => b.color = "green" );
        break; 
      case 2: //S
        blocks = [new Block( -1, 0 ), new Block( 0, 0 ), new Block( 0, -1 ), new Block( 1, -1 )];
        blocks.forEach( b => b.color = "yellow" );
        break; 
      case 3: //L
        blocks = [new Block( -1, -2 ), new Block( -1, -1 ), new Block( -1, 0 ), new Block( 0, 0 )];
        blocks.forEach( b => b.color = "olive" );
        break; 
      case 4: //J
        blocks = [new Block( 0, -2 ),  new Block( 0, -1 ), new Block( -1, 0 ), new Block( 0, 0 )];
        blocks.forEach( b => b.color = "purple" );
        break; 
      case 5: //O
        blocks = [new Block( -1, -1 ), new Block( -1, 0 ), new Block( 0, 0 ), new Block( 0, -1 )];
        blocks.forEach( b => b.color = "teal" );
        break; 
      case 6: //I
        blocks = [new Block( -2, 0 ), new Block( -1, 0 ), new Block( 0, 0 ), new Block( 1, 0 )];
        blocks.forEach( b => b.color = "silver" );
        break; 
    }
    return blocks;
  }
  draw() {
    let blocks = this.calcBlocks();
    for( let b of blocks ) {
      b.draw();
    }
  }
  copy() {
    return new Mino( this.x, this.y, this.rot, this.shape );
  }
}

class Field {
  constructor() {
    this.tiles = [
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    ];
  }
  tileAt( x, y ) {
    return this.tiles[y][x];
  }
  draw() {
    for( let y = 0; y < WIN_HEIGHT/BLOCK_SIZE; y++ ) {
      for( let x = 0; x < WIN_WIDTH/BLOCK_SIZE; x++ ) {
        if( this.tileAt( x, y ) === 1 ) {
          new Block( x, y, "white" ).draw();
        }
        else if( this.tileAt( x, y ) === 2 ) {
          new Block( x, y, "blue" ).draw();
        }
      }
    }
  }
  putBlock( x, y ) {
    this.tiles[y][x] = 2;
  }
  findLineFilled() {
    // フィールドのうち、最下部1ブロックを無視して考える（最下部は壁を表し、削除するフィールドではないため）
    for( let y = 0; y < WIN_HEIGHT/BLOCK_SIZE - 1; y++ ) {
      let isFilled = this.tiles[y].every( t => t !== 0 );
      if( isFilled ) return y;
    }
    return -1;
  }
  cutLine( y ) {
    this.tiles.splice( y, 1 );
    this.tiles.unshift( [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1] );
  }
}

class Game {
  constructor() {
    this.mino    = new Mino( 5, 3, 0, Math.floor( Math.random()*7 ) );
    this.field   = new Field();
    this.minoVx  = 0;
    this.minoVy  = 0;
    this.minoRot = 0;
    this.fc      = 0;
    this.going   = 1;
  }
  static isMinoMovable( mino, field ) {
    let blocks = mino.calcBlocks();
    return blocks.every( b => field.tileAt( b.x, b.y ) === 0 );
  }
  proc() {
    // 下移動処理
    if( this.minoVy !== 0 || this.fc%30 === 29 ) {
      let futureMino = this.mino.copy();
      futureMino.y += 1;
      if( Game.isMinoMovable( futureMino, this.field ) ) {
        this.mino.y += 1;
      }
      // 接地処理
      else {
        let now_fc = this.fc; 
        for( let b of this.mino.calcBlocks() ) {
          this.field.putBlock( b.x, b.y );
          this.mino = new Mino( 5, 2, 0, Math.floor( Math.random()*7 ) );
        }
        // 削除処理
        let line;
        while( ( line = this.field.findLineFilled() ) !== -1 ) {
          this.field.cutLine( line );
        }
      }
      this.minoVy = 0;
    }
    // 左右移動
    if( this.minoVx !== 0 ) {
      let futureMino = this.mino.copy();
      futureMino.x += this.minoVx;
      if( Game.isMinoMovable( futureMino, this.field ) ) {
        this.mino.x += this.minoVx;
      }
      this.minoVx = 0;
    }
    // 回転
    if( this.minoRot !== 0 ) {
      let futureMino = this.mino.copy();
      futureMino.rot += this.minoRot;
      if( Game.isMinoMovable( futureMino, this.field ) ) {
        this.mino.rot += this.minoRot;
      }
      this.minoRot = 0;
    }

    background( 64 );
    this.mino.draw();
    this.field.draw();
    this.fc++;
  }
}