object Exp5 {
 var calc_count = 0

  def printExecTime( process: => Unit ): Unit = {
    val start = System.currentTimeMillis
    process
    println( "処理時間： " + ( System.currentTimeMillis - start ) + " ミリ秒" )
  }

  def main( args: Array[String] ): Unit = {

    val n = args( 0 ).toInt
    printExecTime {
      val pascal_arr = calcPascalValue( n )
      var coin_nums = 0L

      ( 0 until pascal_arr.length ).foreach { i =>
        print( i + " : " )
        ( 0 until pascal_arr.length ).foreach { j =>
          print( pascal_arr( i )( j ) + " " )
        }
        println()
      }

      ( 0 until pascal_arr.length ).foreach { i => coin_nums += calcNecessaryCoins( pascal_arr( n )( i ) ) }
      println( "result = " + coin_nums )

      println( "calc count = " + calc_count )
    }
  }

  def calcPascalValue( num: Int ): Array[Array[Long]] = {
    var result = Array.fill( num + 1, num + 1 )( -1L )
    ( 0 to num ).foreach{ i =>
      calc_count += 1
      result( i )( 0 ) = 1
      result( i )( i ) = 1

      ( 1 to i - 1 ).foreach { j =>
        calc_count += 1
        result( i )( j ) = result( i - 1 )( j ) + result( i - 1 )( j - 1 )
      }
    }

    return result
  }

  def calcNecessaryCoins( values: Long ): Long = {
    val coin_type = Array( 10000L, 5000L, 2000L, 1000L, 500L, 100L, 50L, 10L, 5L, 1L )
    var n         = values
    var result    = 0L

    // 貪欲法による使用する紙幣・硬貨の総数を求める
    coin_type.foreach { coin =>
      calc_count += 1
      result     += n/coin
      n           = n%coin
    }

    return result
  }
}