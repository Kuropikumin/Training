object Exp11 {
  var calc_count = 0
  var memo = Array.empty[Long]

  def printExecTime( process: => Unit ): Unit = {
    val start = System.currentTimeMillis
      process
      println( "処理時間： " + ( System.currentTimeMillis - start ) + " ミリ秒" )
  }

  def main( args: Array[String] ): Unit = {
    val check_cities = args( 0 ).toInt
    memo = Array.fill( check_cities )( -1L )
    printExecTime {
      ( 0 until check_cities - 1 ).foreach { i =>
        calc_count += 1
        
      }
      println( "result = " + calcVodeNum( check_cities ) )
      println( "calc count = " + calc_count )
    }
  }

  def calcVodeNum( num: Int ): Long = {
    var count = 0L
    calc_count += 1
    if( memo( num - 1 ) != -1 ) return memo( num - 1 )
    else {
      if( num <= 2 ) return 1L
      else {
        count += 1                      // 過半数が1つの都市に集まる場合
        count += calcVodeNum( num - 1 ) // 最下位の都市が確定する場合
        // 最下位の都市が i 個の場合
        ( 2 until num ).foreach { i =>
          count += calcVodeNum( i )*calcVodeNum( num - 1 )
        }
      }
      memo( num - 1 ) = count
      return count
    }
  }
}