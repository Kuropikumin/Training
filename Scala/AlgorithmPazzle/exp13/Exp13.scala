object Exp13 {
  var calc_count = 0
  var memo = Map.empty[Long, Long]

  def printExecTime( process: => Unit ): Unit = {
    val start = System.currentTimeMillis
      process
      println( "処理時間： " + ( System.currentTimeMillis - start ) + " ミリ秒" )
  }

  def main( args: Array[String] ): Unit = {
    val nums       = if( args.length == 0 ) 4 else args( 0 ).toInt
    val move_count = if( args.length <  2 ) 3 else args( 1 ).toInt
    var lists      = Array.fill[Array[Array[Int]]]( nums )( Array() )
    printExecTime {
      // ゴールから逆算をすることで計算する
      // ゴールとなる配列のリストを作成
      Range( 2, nums + 1 ).permutations.foreach { i =>
        calc_count += 1
        lists( 0 ) +:= ( 1 +: i.toArray )
      }

      ( 1 to move_count ).foreach { i =>
        lists( i - 1 ).foreach{ arr =>
          ( 1 until nums ).foreach{ j =>
            calc_count += 1
            if( arr( j ) == ( j + 1 ) ) {
              lists( i ) +:= ( arr.take( j + 1 ).reverse ++ arr.takeRight( nums - j - 1 ) )
            }
          }
        }
        lists( i ) = lists( i ).distinct
      }

      println( lists( move_count ).length )
    }

    println( "calc count = " + calc_count )
  }
}