const MACHINE_FILE_PATH = "./picture/test02.png";

// 画像はキャンバスのsetupより前にpreloadする
function preload(){
  img = loadImage( MACHINE_FILE_PATH );
}

function preload(){
  img = loadImage( MACHINE_FILE_PATH );
}

function setup() {
  createCanvas( WIN_WIDTH, WIN_HEIGHT );
  // background( 64 );
  game = new Game();
}
  
function draw() {
  game.proc();
  if( keyIsPressed ) {
    switch( key ) {
      case "w": game.machine.y -= game.machine.speed; break;
      case "a": game.machine.x -= game.machine.speed; break;
      case "s": game.machine.y += game.machine.speed; break;
      case "d": game.machine.x += game.machine.speed; break;
    }
  }
  key = "";
}

function keyIsPressed() {
}

function keyPressed() {
  console.log( Array( game.machine.x, game.machine.y ) );
  // switch( key ) {
  //   case "w": game.machine.y -= game.machine.speed; break;
  //   case "a": game.machine.x -= game.machine.speed; break;
  //   case "s": game.machine.y += game.machine.speed; break;
  //   case "d": game.machine.x += game.machine.speed; break;
  // }

}