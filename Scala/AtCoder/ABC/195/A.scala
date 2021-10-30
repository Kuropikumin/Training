object A {
  def main(args: Array[String]): Unit = {
    val Array( mp, hp ) = io.StdIn.readLine.split( " " ).map{ _.toInt }
    if( hp%mp == 0 ) println( "Yes" )
    else             println( "No" )
  }
}
