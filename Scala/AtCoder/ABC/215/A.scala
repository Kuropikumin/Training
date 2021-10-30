object A {
  def main( args: Array[String] ): Unit = {
    val input  = io.StdIn.readLine
    val answer = "Hello,World!"
    if( input == answer ) println( "AC" )
    else                  println( "WA" )
  }
}