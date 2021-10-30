def sum( x: Int, y: Int, z: Int ): Int = x + y + z

val a = sum _

println( "a( 2, 3, 4 ) = " + a( 2, 3, 4 ) )


def sum2( x: Int, y: Array[Int] ): Int = {
  var count = x
  y.foreach( count += _ )
  count
}

val b = sum2 _

println( "b( 2, Array( 3, 4 ) ) = " + b( 2, Array( 3, 4 ) ) )

val c = sum( 2, _: Int, 4 )
println( "c( 3 ) = " + c( 3 ) )
