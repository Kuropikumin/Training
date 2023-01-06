object Main {
  def main( args: Array[String] ): Unit = {
    var min_v = 10000000000L
    var max_r = -10000000000L

    val check_num = scala.io.StdIn.readInt

    ( 0 until check_num ).foreach { i =>
      val rate = scala.io.StdIn.readLong
      
      if( max_r < rate - min_v ) max_r = rate - min_v
      if( min_v > rate )         min_v = rate
    }
    
    println( max_r )
  }
}