object Exp9 {
  var calc_count = 0

  def printExecTime( process: => Unit ): Unit = {
    val start = System.currentTimeMillis
      process
      println( "処理時間： " + ( System.currentTimeMillis - start ) + " ミリ秒" )
  }

  def main( args: Array[String] ): Unit = {
    val check_ans_num = args( 0 ).toInt
    var octal_strs    = Array.empty[String]
    printExecTime {
      var count     = 0
      var check_num = 1
      while( octal_strs.length < check_ans_num && check_num <= Int.MaxValue ) {
        calc_count += 1
        if( isNarcissisticNumber( check_num ) ) octal_strs :+= check_num.toOctalString
        check_num += 1
      }
      octal_strs.foreach( println( _ ) )
      println( "calc count = " + calc_count )
    }
  }

  def isNarcissisticNumber( num: Int ): Boolean = {
    val octal_str        = num.toOctalString
    var narcissistic_num = 0L

    octal_str.foreach { i =>
      val check_num = i.toString // char型だと数字変換時に文字コードになるため一度string型に変換
      narcissistic_num += Math.pow( check_num.toDouble, octal_str.length ).toInt
    }

    // 一桁だと必ずナルシシスト数になるので除外
    if( narcissistic_num == num && octal_str.length >= 2) return true
    else                                                  return false
  }
}