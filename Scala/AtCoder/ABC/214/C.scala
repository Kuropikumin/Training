object C {
  def main( args: Array[String] ): Unit = {
    val nums           = io.StdIn.readInt
    val next_pass_time = io.StdIn.readLine.split( " " ).map{ _.toLong }
    val get_time       = io.StdIn.readLine.split( " " ).map{ _.toLong }
    var count          = 0

    val get_first_time = calcPassTime( get_time, next_pass_time )
    ( 0 until nums ).foreach{ i =>
      println( get_first_time( i ) )
    }
  }

  def calcPassTime( list: Array[Long], next_pass_time: Array[Long] ): Array[Long] = {
    var result_list = list
    ( 0 until list.length ).foreach { i =>
      val passer_num  = ( first_pass_num + i )%list.length
      val resiver_num = ( first_pass_num + i + 1 )%list.length
      var pass_time   = list( passer_num )
      pass_time += next_pass_time( passer_num )
      if( pass_time > result_list( resiver_num ) ) return result_list
      if( pass_time < result_list( resiver_num ) ) result_list( resiver_num  ) = pass_time
    }
    return result_list
  }
}
