object Main {
  def main( args: Array[String] ): Unit = {
    val Array( a, b, deg ) = scala.io.StdIn.readLine.split( " " ).map{ _.toDouble }
    val rad   = Math.toRadians( deg )
    val s     = ( a*b*Math.sin( rad ) )/2.0
    val c_len = Math.sqrt( Math.pow( a, 2 ) + Math.pow( b, 2 ) - 2*a*b*Math.cos( rad ) )
    val a_height = s*2/a

    println( s )
    println( a + b + c_len )
    println( a_height )
  }
}