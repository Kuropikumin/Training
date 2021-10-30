object A {
  def main( args: Array[String] ): Unit = {
    val input  = io.StdIn.readInt
    if     ( input >= 90 ) println( "expert" )
    else if( input >= 70 ) println( 90 - input )
    else if( input >= 40 ) println( 70 - input )
    else                   println( 40 - input )
  }
}