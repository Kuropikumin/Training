val addMore = ( x: Int ) => x + more

var more = 1
println( "more: " + more )
println( "addMore( 10 ): " + addMore( 10 ) )

more = 30
println( "more: " + more )
println( "addMore( 10 ): " + addMore( 10 ) )


def makeIncreaser( more: Int ) = ( x: Int ) => x + more

val inc1   = makeIncreaser( 1 )
val inc999 = makeIncreaser( 999 )

println( "inc1( 10 ): "   + inc1( 10 ) )
println( "inc999( 10 ): " + inc999( 10 ) )
