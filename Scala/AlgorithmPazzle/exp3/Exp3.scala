object Exp3 {
  def main(args: Array[String]): Unit = {
    var count12length = 0
    (1 to 3999).foreach { i =>
      val ro_num = changeArNum2RoNum( i ) 
      println( i + " : " + ro_num )
      if( ro_num.length == 12 ) count12length += 1
    }
    println( count12length )
  }

  def changeArNum2RoNum( num: Int ): String = {
    var ar_num = num
    var ro_num = ""
    val check_nums      = Map( 1000 -> "M", 100 -> "C", 10 -> "X", 1 -> "I" )
    val check_five_nums = Map( 500 -> "D", 50 -> "L", 5 -> "V" )

    check_nums.keys.foreach{ i =>
      val print_num = ( ar_num/i ).toInt
      if     ( print_num == 4 )                   ro_num += check_nums( i ) + check_five_nums( i*5 ) 
      else if( print_num == 9 )                   ro_num += check_nums( i ) + check_nums( i*10 )
      else if( 5 <= print_num && print_num <= 8 ) ro_num += check_five_nums( i*5 ) + check_nums( i )*( print_num - 5 )
      else                                        ro_num += check_nums( i )*print_num

      ar_num = ar_num%i
    }

    return ro_num
  }
}
