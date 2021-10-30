object Exp2 {
  var calc_count = 0

  def printExecTime( process: => Unit ): Unit = {
    val start = System.currentTimeMillis
    process
    println("処理時間： " + (System.currentTimeMillis - start) + " ミリ秒")
  }

  def main( args: Array[String] ): Unit = {
    val start_number = args( 0 ).toInt 
    val end_number   = args( 1 ).toInt
    val station_nums = args( 2 ).toInt

    printExecTime { 
      val n                  = Math.abs( end_number - start_number ).toInt
      val outer_station_nums = n - 1
      val inner_station_nums = station_nums - n - 1

      val answer = Math.pow( 2, outer_station_nums ).toInt + Math.pow( 2, inner_station_nums ).toInt - 1

      println( "total combination = " + answer )

      // println( "calc count = " + calc_count )
    }
  }
}
