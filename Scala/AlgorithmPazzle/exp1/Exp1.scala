object Exp1 {
  var calc_count = 0

  def printExecTime(process: => Unit): Unit = {
    val start = System.currentTimeMillis
    process
    println("処理時間： " + (System.currentTimeMillis - start) + " ミリ秒")
  }

  def main( args: Array[String] ): Unit = {
    val nums   = args( 0 ).toInt
    var result = 0

    printExecTime { 
      ( 0 to nums ).foreach { rock =>
        ( 0 to nums - rock ).foreach { scissors =>
          calc_count += 1
          val paper = nums - rock - scissors
          
          if( isWinTheGame( rock, scissors, paper ) ) result += 1
        }
      }
      println( "Win the game nums = " + result )
      println( "calc count = " + calc_count )
    }
  }

  def isWinTheGame( r: Int, s: Int, p: Int ): Boolean = {
    val result = Array( r, s, p ).sorted

    if( result( 2 ) > result( 1 ) ) return true
    else                            return false
  }
}
