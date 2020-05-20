object Exp5 {
  def main(args: Array[String]): Unit = {

    val check_num = 45
    var total_sheet_num = 0.toLong

    ( 0 to check_num ).foreach{ i =>
      val calc_num = calcCombination( check_num, i ) 
      val sheet_num = calcNumberOfSheets( calc_num )
      println( i + " > " + calc_num + " : " + sheet_num )
      total_sheet_num += sheet_num
    }
    println( "total_sheet_num : " + total_sheet_num )
  }

  def calcCombination( n_num: Int, r_num: Int ): Long = {
    val n = n_num
    val r = if ( n_num - r_num < r_num ) n_num - r_num else r_num

    var answer_num = 1.0
    if( r == 0 ) return 1
    else {
      ( 1 to r ).foreach { i =>
        answer_num /= i.toDouble
        answer_num *= ( n - i + 1 ).toDouble
      }
    }
    return answer_num.toLong
  }

  def calcNumberOfSheets( num: Long ): Long = {
    var total_amount_of_money = num
    var total_sheet_num       = 0.toLong
    val amount_of_money       = Vector( 10000, 5000, 2000, 1000, 500, 100, 50, 10, 5, 1 )

    amount_of_money.foreach { i =>
      total_sheet_num += total_amount_of_money/i.toLong
      total_amount_of_money = total_amount_of_money%i.toLong
    }

    return total_sheet_num
  }
}
