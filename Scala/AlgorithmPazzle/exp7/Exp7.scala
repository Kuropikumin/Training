object Exp7 {
  def main(args: Array[String]): Unit = {

    val CHECK_ARRAY_LENGTH = 15
    var total_ways         = 0.toLong

    ( 1 until CHECK_ARRAY_LENGTH ).foreach{ i =>
      total_ways += ( CHECK_ARRAY_LENGTH - i ).toLong*calcPermutation( CHECK_ARRAY_LENGTH, i - 1 )*i
    }
    println( "total_sheet_num : " + total_ways )
  }

  def calcPermutation( n_num: Int, r_num: Int ): Long = {
    val n = n_num
    val r = r_num
    var answer_num = 1.toLong

    if( r == 0 ) return 1
    else {
      ( 1 to r ).foreach { i =>
        answer_num *= ( n + 1 - i ).toLong
      }
    }
    return answer_num
  }
}
