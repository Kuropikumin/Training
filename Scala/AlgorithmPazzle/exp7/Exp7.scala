object Exp7 {
  var calc_count = 0

  def printExecTime( process: => Unit ): Unit = {
    val start = System.currentTimeMillis
      process
      println( "処理時間： " + ( System.currentTimeMillis - start ) + " ミリ秒" )
  }

  def main( args: Array[String] ): Unit = {
    val character_type = args( 0 ).toInt
    printExecTime {
      var result = 0L
      ( 0 until character_type ).foreach { i =>
        result += ( character_type - i )*i*permutation( character_type, character_type - i - 1 )
      }
      println( "result = " + result )
      println( "calc count = " + calc_count )
    }
  }

  def permutation( n: Int, r: Int ): Long = {
    calc_count += 1
    if     ( n == r ) return 1L
    else if( r == 0 ) return 1L
    else              return n.toLong*permutation( n - 1, r - 1 )
  }
}