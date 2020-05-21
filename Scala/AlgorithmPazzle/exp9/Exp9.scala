object Exp9 {
  def main( args: Array[String] ): Unit = {
    val BASE_NUM      = 8
    val ANSWER_LENGTH = 8
    var answer_num    = Vector.empty[Vector[Int]]
    val search_range  = Math.pow( BASE_NUM, calcSearchRange( BASE_NUM ) + 1).toLong
    var check_num     = Math.pow( BASE_NUM, 1 ).toInt

    while( answer_num.length < ANSWER_LENGTH && check_num.toLong < search_range ) {
      if( checkNarcissisticNumber( check_num, BASE_NUM ) ) { 
        answer_num = answer_num :+ changeNBaseNum( check_num, BASE_NUM )
      }
      check_num += 1
    }

    answer_num.foreach{ i =>
      val len = i.length
      ( 1 to len ).foreach{ j =>
        print( i( len - j ) )
      }
      println()
    }
  }

  def calcSearchRange( base_num: Int ): Int = {
    var digit = 1
    while( digit*( Math.pow( base_num - 1, digit )) > Math.pow( base_num, digit - 1 )) digit += 1
    return digit
  }

  def checkNarcissisticNumber( num: Int, base_num: Int ): Boolean = {
    var answer_num    = 0
    val changed_base = changeNBaseNum( num, base_num )
    (0 until changed_base.length).foreach{ i =>
      answer_num += Math.pow( changed_base(i), changed_base.length ).toInt
    }

    if( answer_num == num ) return true
    else                    return false
  }

  def changeNBaseNum( num: Int, base_num: Int ): Vector[Int] = {
    var changed_num = Vector.empty[Int]
    var n           = num

    while( n != 0 ) {
      changed_num = changed_num :+ n%base_num
      n           = n/base_num
    }

    return changed_num
  }
}
