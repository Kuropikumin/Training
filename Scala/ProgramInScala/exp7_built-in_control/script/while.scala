def gcdLoop( x: Long, y: Long ): Long = {
  if     ( y > x )    gcdLoop( y, x )
  else if( x%y == 0 ) y
  else                gcdLoop( y, x%y )
}

if( args.length < 2 ) {
  println( "Usage: scala while.scala num1 num2" )
  sys.exit( 1 )
}

val ( a, b ) = ( args( 0 ).toLong, args( 1 ).toLong )

println( "Greatest common divisor " + a + " : " + b + " = " + gcdLoop( Math.abs( a ), Math.abs( b ) ) )
