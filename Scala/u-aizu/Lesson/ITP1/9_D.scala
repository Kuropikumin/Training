object Main {
  def main( args: Array[String] ): Unit = {
    var str        = scala.io.StdIn.readLine
    val order_num  = scala.io.StdIn.readInt

    ( 0 until order_num ).foreach{ i =>
      val order = scala.io.StdIn.readLine.split( " " )
      val start = order( 1 ).toInt
      val end   = order( 2 ).toInt
      order( 0 ) match {
        case "reverse" => {
          str = str.patch( start, str.substring( start, end + 1 ).reverse, end - start + 1 )
        }
        case "replace" => {
          str = str.patch( start, order( 3 ), order( 3 ).length )
        }
        case "print" => {
          println( str.substring( start, end + 1 ) )
        }
      }
    }
  }
}