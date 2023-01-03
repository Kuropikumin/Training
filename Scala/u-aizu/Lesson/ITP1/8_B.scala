object Main {
  def main( args: Array[String] ): Unit = {
    var continue_flag = true

    while( continue_flag ) {
      val str = scala.io.StdIn.readLine()
      var sum = 0

      if( str == "0" ) continue_flag = false
      else {
        str.map{ sum += _.asDigit }
        println( sum )
      }
    }
  }
}