object A {
  def main( args: Array[String] ): Unit = {
    val nums        = io.StdIn.readInt
    var answer      = 0
    if( nums <= 125 )      answer = 4
    else if( nums <= 211 ) answer = 6
    else                   answer = 8
    println( answer )
  }
}