object Main {
  def main( args: Array[String] ): Unit = {
    val s = scala.io.StdIn.readLine()*2
    val p = scala.io.StdIn.readLine()

    if( s.contains( p ) ) println( "Yes" )
    else                  println( "No" )
  }
}