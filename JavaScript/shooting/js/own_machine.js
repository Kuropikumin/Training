const WIN_WIDTH  = 360;
const WIN_HEIGHT = 540;
const BLOCK_SIZE = 30;

class Machine {
  constructor( x, y, power, speed, image = img ) {
    this.x = x;
    this.y = y;
    this.power = power;
    this.speed = speed;
    this.image = img;
  }
  draw() {
    image( this.image, this.x, this.y, 50, 50 );
  }
}

// class Mino {
//  constructor( x, y, rot, shape ) {
//    this.x = x;
//    this.y = y;
//    this.rot = rot;
//    this.shape = shape;
//  }
//  calcBlocks() {
//    let blocks = this.createBlocks();
//    let rot = ( 40000000 + this.rot )%4;
//    for( let r = 0; r < rot; r++ ) {
//      blocks = blocks.map( b => new Block( -b.y, b.x, b.color ) );
//    }
//    blocks.forEach( b => ( b.x += this.x, b.y += this.y ) );
//    return blocks;
//  }
//  createBlocks() {
//    let blocks = [];
//    switch( this.shape ) {
//      case 0: //T
//        blocks = [new Block( -1, 0 ), new Block( 0, 0 ), new Block( 0, -1 ), new Block( 1, 0 )];
//        blocks.forEach( b => b.color = "red" );
//        break; 
//      case 1: //Z
//        blocks = [new Block( -1, -1 ), new Block( 0, -1 ), new Block( 0, 0 ), new Block( 1, 0 )];
//        blocks.forEach( b => b.color = "green" );
//        break; 
//      case 2: //S
//        blocks = [new Block( -1, 0 ), new Block( 0, 0 ), new Block( 0, -1 ), new Block( 1, -1 )];
//        blocks.forEach( b => b.color = "yellow" );
//        break; 
//      case 3: //L
//        blocks = [new Block( -1, -2 ), new Block( -1, -1 ), new Block( -1, 0 ), new Block( 0, 0 )];
//        blocks.forEach( b => b.color = "olive" );
//        break; 
//      case 4: //J
//        blocks = [new Block( 0, -2 ),  new Block( 0, -1 ), new Block( -1, 0 ), new Block( 0, 0 )];
//        blocks.forEach( b => b.color = "purple" );
//        break; 
//      case 5: //O
//        blocks = [new Block( -1, -1 ), new Block( -1, 0 ), new Block( 0, 0 ), new Block( 0, -1 )];
//        blocks.forEach( b => b.color = "teal" );
//        break; 
//      case 6: //I
//        blocks = [new Block( -2, 0 ), new Block( -1, 0 ), new Block( 0, 0 ), new Block( 1, 0 )];
//        blocks.forEach( b => b.color = "silver" );
//        break; 
//    }
//    return blocks;
//  }
//  draw() {
//    let blocks = this.calcBlocks();
//    for( let b of blocks ) {
//      b.draw();
//    }
//  }
//  copy() {
//    return new Mino( this.x, this.y, this.rot, this.shape );
//  }
//// }
//
//class Field {
//  constructor() {
//    this.tiles = [
//      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
//      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
//      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
//      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
//      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
//      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
//      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
//      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
//      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
//      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
//      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
//      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
//      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
//      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
//      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
//      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
//      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
//      [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
//    ];
//  }
//  tileAt( x, y ) {
//    return this.tiles[y][x];
//  }
//  draw() {
//    for( let y = 0; y < WIN_HEIGHT/BLOCK_SIZE; y++ ) {
//      for( let x = 0; x < WIN_WIDTH/BLOCK_SIZE; x++ ) {
//        if( this.tileAt( x, y ) === 1 ) {
//          new Block( x, y, "white" ).draw();
//        }
//        else if( this.tileAt( x, y ) === 2 ) {
//          new Block( x, y, "blue" ).draw();
//        }
//      }
//    }
//  }
//  putBlock( x, y ) {
//    this.tiles[y][x] = 2;
//  }
//  findLineFilled() {
//    // フィールドのうち、最下部1ブロックを無視して考える（最下部は壁を表し、削除するフィールドではないため）
//    for( let y = 0; y < WIN_HEIGHT/BLOCK_SIZE - 1; y++ ) {
//      let isFilled = this.tiles[y].every( t => t !== 0 );
//      if( isFilled ) return y;
//    }
//    return -1;
//  }
//  cutLine( y ) {
//    this.tiles.splice( y, 1 );
//    this.tiles.unshift( [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1] );
//  }
//}
//
class Game {
  constructor() {
    this.machine = new Machine( WIN_WIDTH*0.5, WIN_HEIGHT*0.8, 5, 3, img );
  }
  proc() {
    background( 64 );
    this.machine.draw();
    this.fc++;
  }
}