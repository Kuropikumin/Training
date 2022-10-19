function setup() {
  createCanvas( WIN_WIDTH, WIN_HEIGHT );
  background( "green" );
  game = new Game();
}
  
function draw() {
  game.proc();
}

function mousePressed() {
  let w = BLOCK_SIZE;
  let x = floor( mouseX/w );
  let y = floor( mouseY/w );

  // オセロ盤内をクリックした場合の処理
  if( ( 0 <= x && x < BLOCK_NUM ) && ( 0 <= y && y < BLOCK_NUM ) ) {
    if( game.field.isPlaseable( x, y, game.turn ) ) {
      game.putDisk( x, y );
    }
  } 
}