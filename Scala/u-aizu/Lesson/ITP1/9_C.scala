object Main {
  def main( args: Array[String] ): Unit = {
    val battles_num = scala.io.StdIn.readInt
    var points = Array( 0, 0 )

    ( 0 until battles_num ).foreach{ i =>
      val Array( p1_str, p2_str ) = scala.io.StdIn.readLine.split( " " )
      if( p1_str == p2_str ) {
        points( 0 ) += 1
        points( 1 ) += 1
      }
      else if( p1_str < p2_str ) {
        points( 1 ) += 3
      }
      else {
        points( 0 ) += 3
      }
    }

    println( points( 0 ) + " " + points( 1 ) )
  }
}