object Exp6 {
  var calc_count = 0
  var memo = Array.fill( 1000 + 1, 1000 + 1 )( -1 )

  def printExecTime( process: => Unit ): Unit = {
    val start = System.currentTimeMillis
      process
      println( "処理時間： " + ( System.currentTimeMillis - start ) + " ミリ秒" )
  }

  def main( args: Array[String] ): Unit = {
    val check_square_num = args( 0 ).toInt
    printExecTime { 
      var result = 0

      ( 1 to 1000 ).foreach { long_edge =>
        ( 1 to long_edge ).foreach { short_edge =>
          val square_num = createSquareNum( short_edge, long_edge )
          if( square_num == 20 ) result += 1
        } 
      }
      println( "result = " + result )
      println( "calc count = " + calc_count )
    }
  }

  def createSquareNum( short_edge: Int, long_edge: Int ): Int = {
    calc_count += 1

    // メモの追加（計算量：993,931）
    if( memo( long_edge )( short_edge) != -1 ) return memo( long_edge )( short_edge )
    else {
      // 通常の処理（計算回数：2,697,262）
      if( short_edge > long_edge ) return createSquareNum( long_edge, short_edge )
      else {
        val square_num      = long_edge/short_edge
        val next_short_edge = long_edge%short_edge
        if( next_short_edge == 0 ) return square_num
        else {
          // メモの記録
          memo( long_edge )( short_edge ) = square_num + createSquareNum( next_short_edge, short_edge )
          return memo( long_edge )( short_edge )
        }
      }
    }
  }
}