object Exp3 {
  var calc_count     = 0
  var roman_numerals = Array.empty[String]

  def printExecTime(process: => Unit): Unit = {
    val start = System.currentTimeMillis
    process
    println("処理時間： " + (System.currentTimeMillis - start) + " ミリ秒")
  }

  def main( args: Array[String] ): Unit = {
    val MAX_NUM      = 4000 - 1 // ローマ数字では 0 の概念がないため 1 ~ 3999 の3999文字
    val count_length = args( 0 ).toInt
    var result       = 0

    roman_numerals = Array.fill[String]( MAX_NUM )( "" )

    printExecTime { 
      ( 1 to MAX_NUM ).foreach { i =>
        roman_numerals( i - 1 ) = changeNumToRoman( i )
        if( roman_numerals( i - 1 ).length == count_length ) result += 1
        println( i + " : " + roman_numerals( i - 1 ) )
      }

      println( "roman numerals length " + count_length + " is " + result )
      println( "calc count = " + calc_count )
    }
  }

  def changeNumToRoman( n: Int ): String = {
    val map_roman_arabic = Map( 1 -> "I", 5 -> "V", 10 -> "X", 50 -> "L", 100 -> "C", 500 -> "D", 1000 -> "M" )
    val check_num        = Array( 1000, 100, 10, 1 )
    var num              = n
    var result           = ""
    var count            = 0
    
    // メモによる高速化（計算量5106）
    while( num > 0 ) {
      val key = check_num( count )
      // すでに計算している場合
      if( roman_numerals( num - 1 ) != "" ) {
        result += roman_numerals( num - 1)
        num = 0
      }
      else {
        calc_count += 1

        val roman_num = num/key

        if ( roman_num == 9 )     result += map_roman_arabic( key )   + map_roman_arabic( key*10 )
        else if( roman_num >= 5 ) result += map_roman_arabic( key*5 ) + map_roman_arabic( key )*( roman_num - 5 )
        else if( roman_num == 4 ) result += map_roman_arabic( key )   + map_roman_arabic( key*5 )
        else                      result += map_roman_arabic( key )*roman_num
      }
      count += 1
      num = num%key

    }

    // すべてのローマ数字を都度計算（計算量 15996回）
    // check_num.foreach { key =>
    //   calc_count += 1
    //   val roman_num = num/key
    //   if ( roman_num == 9 ) { 
    //     result += map_roman_arabic( key ) + map_roman_arabic( key*10 )
    //   }
    //   else if( roman_num >= 5 ) result += map_roman_arabic( key*5 ) + map_roman_arabic( key )*( roman_num - 5 )
    //   else if( roman_num == 4 ) result += map_roman_arabic( key ) + map_roman_arabic( key*5 )
    //   else                      result += map_roman_arabic( key )*roman_num
    //   num = num%key
    // }

    return result
  }
}
