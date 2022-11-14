const WIN_WIDTH  = 4800;
const WIN_HEIGHT = 420;
const TILE_SIZE  = 30;
const TILE_NUM   = 10;

class Field {
  constructor() {
    this.tiles = [
      [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1],
      [-1,  1,  1,  1,  1,  1,  1,  1,  1, -1],
      [-1,  2, -1,  1, -1, -1, -1, -1,  2, -1],
      [-1,  1, -1,  1, -1, -1, -1, -1,  1, -1],
      [-1,  1, -1,  1, -1, -1, -1, -1,  1, -1],
      [-1,  2, -1,  1, -1, -1, -1, -1,  2, -1],
      [-1,  1, -1,  1, -1, -1, -1, -1,  1, -1],
      [-1,  1, -1,  1, -1, -1, -1, -1,  1, -1],
      [-1,  1,  1,  0,  1,  1,  1,  1,  1, -1],
      [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1],
    ];
  }
  tileAt( x, y ) {
    return this.tiles[y][x];
  }
  movable( x, y, dx, dy ) {
    if( this.tileAt( x + dx, y + dy ) != -1 ) return true;
    else                                      return false;
  }
  ifFinish() {
    let count = 0;
    for( let y = 0; y < TILE_NUM; y++ ) {
      for( let x = 0; x < TILE_NUM; x++ ) {
        if( this.tiles[y][x] != -1 || this.tiles[y][x] != 0 ) {
          count += 1;
        }
      }
    }
    if( count == 0 ) return true;
    else             return false;
    console.log( count );
  }
  draw() {
    let img;
    for( let y = 0; y < TILE_NUM; y++ ) {
      for( let x = 0; x < TILE_NUM; x++ ) {
        switch( this.tileAt( x, y ) ) {
          case 0:  img = no_img; break;
          case -1: img = bl_img; break;
          case 1:  img = sb_img; break;
          case 2:  img = bb_img; break;
        }
        image( img, x*TILE_SIZE, y*TILE_SIZE, TILE_SIZE, TILE_SIZE );
      }
    }
  }
}

class Packman {
  constructor( img ) {
    this.x       = 3;
    this.y       = 8;
    this.dx      = 0;
    this.dy      = -1;
    this.movable = true;
    this.count   = 0;
  }
  draw( ) {
    let img = pks_img[this.count%4];
    let delta_dx = 0, delta_dy = 0;
    if( this.movable ) {
      delta_dx = TILE_SIZE/4*( this.count%4 )*this.dx;
      delta_dy = TILE_SIZE/4*( this.count%4 )*this.dy;
    }

    push();
    translate( this.x*TILE_SIZE + TILE_SIZE/2 + delta_dx, this.y*TILE_SIZE + TILE_SIZE/2 + delta_dy );
    imageMode( CENTER );
    rotate( this.direction() );
    image( img, 0, 0, TILE_SIZE, TILE_SIZE );
    pop();
    console.log( this.count, delta_dx, delta_dy );
  }
  direction( ) {
    let d = 0;
    if( this.dx == 0 ) {
      if( this.dy == -1 ) d = 90;
      else                d = 270;
    }
    else {
      if( this.dx == -1 ) d = 0;
      else                d = 180;
    }
    return radians( d );
  }
}

class Game {
  constructor() {
    this.field   = new Field();
    this.packman = new Packman( );
    this.fc      = 0;
  }
  proc() {
    if( !this.field.ifFinish() ) {
      this.field.draw();
      this.packman.draw();
    } 
  }
}