object Exp10 {
  var calc_count = 0

  def printExecTime( process: => Unit ): Unit = {
    val start = System.currentTimeMillis
      process
      println( "処理時間： " + ( System.currentTimeMillis - start ) + " ミリ秒" )
  }

  def main( args: Array[String] ): Unit = {
    val PREFECTURE_NUM        = 47
    val PARLIAMENTARIANS_NUM  = 289

    var prefecture_population = Map.empty[String, Int]
    var max_poplation         = 0

    printExecTime {
      // データの作成（実際のデータはdata.txt参照）
      ( 0 until PREFECTURE_NUM ).foreach { i =>
        calc_count += 1
        val Array( prefecture, population ) = scala.io.StdIn.readLine.split( " " )
        if( max_poplation < population.toInt ) max_poplation = population.toInt
        prefecture_population ++= Map( prefecture -> population.toInt )
      }

      val check_num = Range( 1, max_poplation + 1 ).toArray
      val divided_num = calcDividedNum( prefecture_population, check_num, PARLIAMENTARIANS_NUM )
      println( divided_num )
      prefecture_population.keys.foreach { key =>
        println( key + " : " + Math.ceil( prefecture_population( key )/divided_num.toDouble ).toInt )
      }
      println( "calc count = " + calc_count )
    }
  }

  def calcDividedNum( list: Map[String, Int], check_num: Array[Int], ans: Int ): Int = {
    var left  = 0
    var right = check_num.length - 1
    var flag  = false
    var middle = check_num( ( check_num( left ) + check_num( right ) )/2 )

    // 2分木探索
    while( !flag && left < right ) {
      calc_count += 1
      middle = check_num( ( check_num( left ) + check_num( right ) )/2 ) 
      var total_num = 0
      list.keys.foreach { key =>
        calc_count += 1
        total_num += Math.ceil( list( key )/middle.toDouble ).toInt
      }

      println( "total num = " + total_num + ", middle = " + middle )
      if     ( total_num == ans ) flag  = true
      else if( total_num <  ans ) right = middle - 1
      else                        left  = middle + 1
    }

    // 見つからない場合は -1 を返す
    if( !flag ) return -1
    else        return middle
  }
}