function setup() {
  createCanvas( WIN_WIDTH, WIN_HEIGHT );
  background( 64 );
  game = new Game();
}
  
function draw() {
  if( game.going == 1 ) {
    game.proc();
  }
}

function keyPressed() {
  if( key === "ArrowLeft" )  game.minoVx  = -1;
  if( key === "ArrowRight" ) game.minoVx  = 1;
  if( key === "ArrowDown" )  game.minoVy  = 1;
  if( key === "q" )          game.minoRot = -1;
  if( key === "r" )          game.minoRot = 1;
  if( key === " " )          game.going = ( game.going^1 );
}