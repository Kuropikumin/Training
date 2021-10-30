val n    = args( 0 ).toInt
val half =
  if( n%2 == 0 ) n/2
  else           throw new RuntimeException( "n must be even" )
