object Main {
  def main( args: Array[String] ): Unit = {
    var max_value = -1000000000L
    var max_rate  = -1000000000L
    val check_num = scala.io.StdIn.readInt

    var rate = Array[Long]()
    ( 0 until check_num ).foreach { i =>
      rate = rate :+ scala.io.StdIn.readLong
    }
    
    ( rate.length - 1 to 0 by -1 ).foreach{ i =>
      if( max_rate < ( max_value - rate( i ) ) ) max_rate = max_value - rate( i )

      if( max_value < rate( i ) ) max_value = rate( i )
    }

    println( max_rate )
  }
}