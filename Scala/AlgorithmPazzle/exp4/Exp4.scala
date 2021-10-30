object Exp4 {
  
  var calc_count = 0

  def printExecTime( process: => Unit ): Unit = {
    val start = System.currentTimeMillis
    process
    println( "処理時間： " + ( System.currentTimeMillis - start ) + " ミリ秒" )
  }

  def main( args: Array[String] ): Unit = {
    val check_light_num = args( 0 ).toInt
    var light_nums      = Array.fill( 60 )( -1 )

    printExecTime { 
      // メモの作成
      ( 0 until 60 ).foreach { i =>
        calc_count += 1
        val ten_place = if( i < 10 ) 0 else ( i/10 )
        val one_place = ( i%10 )
        light_nums( i ) = calcLightNum( ten_place ) + calcLightNum( one_place )
      }

      var result = 0
      ( 0 until 24 ).foreach { hour => 
        ( 0 until 60 ).foreach { min =>
          ( 0 until 60 ).foreach { sec =>
            calc_count += 1
            val light_num = light_nums( hour ) + light_nums( min ) + light_nums( sec )
            if( light_num == check_light_num ) result += 1
            println( hour + ":" + min + ":" + sec + " = " + light_num )
          } 
        }
      }

      println( "result = " + result )
      println( "calc count = " + calc_count )
    }
  }

  def calcLightNum( num: Int ): Int = {
    val light_2 = Array( 1 )
    val light_3 = Array( 7 )
    val light_4 = Array( 4 )
    val light_5 = Array( 2, 3, 5 )
    val light_6 = Array( 0, 6, 9 )
    if     ( light_2.contains( num ) ) return 2
    else if( light_3.contains( num ) ) return 3
    else if( light_4.contains( num ) ) return 4
    else if( light_5.contains( num ) ) return 5
    else if( light_6.contains( num ) ) return 6
    else                               return 7
  }
}