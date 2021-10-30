object Exp12 {
  var calc_count = 0

  def printExecTime( process: => Unit ): Unit = {
    val start = System.currentTimeMillis
      process
      println( "処理時間： " + ( System.currentTimeMillis - start ) + " ミリ秒" )
  }

  def main( args: Array[String] ): Unit = {
    val check_pi_digit = args( 0 ).toInt
    printExecTime {
      val result = calcDenominator( check_pi_digit )
      println( Math.PI )
      println( result( 0 ) + " : " + result( 1 ) + " = " + result( 0 )/result( 1 ).toDouble )
      println( "calc count = " + calc_count )
    }
  }

  def calcDenominator( check_pi_digit: Int ): Array[Long] = {
    val ten_digit    =  Math.pow( 10, check_pi_digit ).toLong
    val check_pi_num = ( Math.PI*ten_digit ).toLong
    var check_num = 0L
    var flag = false

    while( !flag ) {
      check_num += 1
      calc_count += 1
      val check1 = check_pi_num*check_num
      val check2 = ( check_pi_num + 1 )*check_num
      
      if( check2/ten_digit - check1/ten_digit > 0 ) flag = true
    }

    return Array( ( check_pi_num + 1 )*check_num/ten_digit, check_num )
  }
}