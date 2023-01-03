object Main {
  def main( args: Array[String] ): Unit = {
    var continue_flag = true

    while( continue_flag ) {
      var str = scala.io.StdIn.readLine
      if( str == "-" ) continue_flag = false
      else {
        val change_num = scala.io.StdIn.readInt

        ( 0 until change_num ).foreach { i =>
          val num = scala.io.StdIn.readInt
          val slice_str = str.substring( 0, num )
          str = str.substring( num ) + slice_str
          println( str + " : " + slice_str + " : " + str.substring( num ) )
        }

        println( str )
      }
    }
  }
}