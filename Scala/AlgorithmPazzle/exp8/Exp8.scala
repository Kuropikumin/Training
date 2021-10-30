object Exp8 {
  var calc_count = 0

  def printExecTime( process: => Unit ): Unit = {
    val start = System.currentTimeMillis
      process
      println( "処理時間： " + ( System.currentTimeMillis - start ) + " ミリ秒" )
  }

  def main( args: Array[String] ): Unit = {
    val cell_rows = args( 0 ).toInt
    val cell_cols = args( 1 ).toInt

    printExecTime {
      println( cell_cols + cell_rows - 1 )
      println( "calc count = " + calc_count )
    }
  }
}