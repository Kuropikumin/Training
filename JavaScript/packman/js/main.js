const SMALL_BALL_FILE_PATH = "./picture/small_ball.png";
const BIG_BALL_FILE_PATH =   "./picture/big_ball.png";
const BLOCK_FILE_PATH =      "./picture/block.png";
// const PACKMAN01_FILE_PATH =  "./picture/packman01.png";
// const PACKMAN02_FILE_PATH =  "./picture/packman02.png";
// const PACKMAN03_FILE_PATH =  "./picture/packman03.png";
const PACKMANS_FILE_PATH =   "./picture/packman";
const PACKMANS_NUM =         3;
const NOTHTING_FILE_PATH =   "./picture/nothing.png";

// 画像はキャンバスのsetupより前にpreloadする
function preload(){
  sb_img = loadImage( SMALL_BALL_FILE_PATH );
  bb_img = loadImage( BIG_BALL_FILE_PATH );
  bl_img = loadImage( BLOCK_FILE_PATH );
  pks_img = [];
  for( let i = 0; i < PACKMANS_NUM; i++ ) {
    let packman_path = PACKMANS_FILE_PATH + "0" + ( i + 1 ) + ".png";
    pks_img.push( loadImage( packman_path ) );
  }
  pks_img.push( loadImage( PACKMANS_FILE_PATH + "02.png" ) );
  // pk1_img = loadImage( PACKMAN01_FILE_PATH );
  // pk2_img = loadImage( PACKMAN02_FILE_PATH );
  // pk3_img = loadImage( PACKMAN02_FILE_PATH );
  no_img = loadImage( NOTHTING_FILE_PATH );
}

function setup() {
  createCanvas( WIN_WIDTH, WIN_HEIGHT );
  // background( "black" );
  game = new Game();
}
  
function draw() {
  if( frameCount%5 == 0 ) {
    game.proc();
    if( frameCount%20 == 0 ) {
      if( game.field.movable( game.packman.x, game.packman.y, game.packman.dx, game.packman.dy ) ) {
        game.packman.x += game.packman.dx;
        game.packman.y += game.packman.dy;
        game.field.tiles[game.packman.y][game.packman.x] = 0;
        game.packman.movable = true;
      }
      else {
        game.packman.movable = false;
      }
    }
    game.packman.count += 1;
  }
}

function keyPressed() {
  let dx = 0, dy = 0;
  switch( key ) {
    case "w": dy = -1; break;
    case "a": dx = -1; break;
    case "s": dy = 1;  break;
    case "d": dx = 1;  break;
  }
  if( game.field.movable( game.packman.x, game.packman.y, dx, dy ) ) {
    game.packman.dx = dx;
    game.packman.dy = dy;
  }
}