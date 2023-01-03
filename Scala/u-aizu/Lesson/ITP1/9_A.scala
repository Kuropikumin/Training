object Main {
  def main( args: Array[String] ): Unit = {
    var continue_flag = true
    var sum = 0
    val w = scala.io.StdIn.readLine

    while( continue_flag ) {
      val check_word_list = scala.io.StdIn.readLine.split( " " )
      check_word_list.foreach{ i =>
        if( i == "END_OF_TEXT" ) continue_flag = false

        if( continue_flag ) {
          if ( i.toLowerCase == w ) sum += 1
        }
      }
    }

    println( sum )
  }
}