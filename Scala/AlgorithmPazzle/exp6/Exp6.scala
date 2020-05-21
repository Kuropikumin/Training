object Exp6 {
  def main(args: Array[String]): Unit = {
    val MAX_LENGTH   = 1000
    val LOOP_OUT_NUM = 20
    var count = 0

    ( 1 to MAX_LENGTH ).foreach { i =>
      (1 to i).foreach { j =>
        var create_square_num = 0
        var long_edge  = i
        var short_edge = j
        while( short_edge > 0 && create_square_num <= 20 ) {
          create_square_num += long_edge/short_edge
          val tmp_edge = short_edge
          short_edge = long_edge%tmp_edge
          long_edge  = tmp_edge
        }

        if( create_square_num == 20 ) count += 1
      }
    }

    println( "count : " + count )

  }
}
