object Main {
  def main( args: Array[String] ): Unit = {
    val nums = scala.io.StdIn.readLine.split( " " ).map{ _.toDouble }
    pritln( Math.sqrt( Math.pow( nums( 2 ) - nums( 0 ), 2 ) + Math.pow( nums( 3 ) - nums( 1 ), 2 ) ) )
  }
}