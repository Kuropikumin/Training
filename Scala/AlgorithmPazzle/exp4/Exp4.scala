object Exp4 {
  def main(args: Array[String]): Unit = {
    val MAX_TIME  = 3600*23 + 60*59 + 59 // 1日の最大秒数
    val check_num = 30
    var count = 0
    (0 to MAX_TIME).foreach{ i =>
      val check_time = changeNum2Time( i )
      var number_of_lights = 0
      check_time.foreach{ number_of_lights += countNumberOfLight( _ ) }
      if( number_of_lights == check_num ) count += 1
    }

    println( count )
  }

  def countNumberOfLight( num: Int ): Int = {
    if     ( num == 1 )                        return 2
    else if( num == 7 )                        return 3
    else if( num == 4 )                        return 4
    else if( num == 8 )                        return 7
    else if( num == 0 || num == 6 || num == 9) return 6
    else                                       return 5
  }

  def changeNum2Time( num: Int ): Array[Int] = {
    var time_num = num
    val hours    = time_num/3600
    time_num     = time_num%3600
    val minutes  = time_num/60
    time_num     = time_num%60
    val seconds  = time_num

    return Array( hours/10, hours%10, minutes/10, minutes%10, seconds/10, seconds%10 )

  }
}
