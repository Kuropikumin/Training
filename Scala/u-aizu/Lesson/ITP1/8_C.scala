object Main {
  val char_type = 26
  val a_int     = 'a'.toInt
  def main( args: Array[String] ): Unit = {
    var str_num = Array.fill[Int]( char_type )( 0 )
    scala.io.Source.fromInputStream( System.in ).getLines.foreach { line =>
      line.map { c =>
        var check_i = c.toLower.toInt
        if( a_int <= check_i && check_i < a_int + char_type ) {
          str_num( check_i - a_int ) += 1
        }
      }
    }
    ( 0 until str_num.length ).foreach { i =>
      println( ( a_int + i ).toChar + " : " + str_num( i ) )
    }
  }
}