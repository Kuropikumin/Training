val someNumbers = List( -11, -10, -5, 0, 5, 10 )
someNumbers.foreach( ( x ) => println( x ) )

val filterSomeNumbers = someNumbers.filter( _ > 3 )
println( "filterSomeNumbers = " + filterSomeNumbers )
