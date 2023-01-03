object Main {
  def main( args: Array[String] ): Unit = {
    var sum = 0
    val check_num = scala.io.StdIn.readInt

    ( 0 until check_num ).foreach { i =>
      val num = scala.io.StdIn.readLong
      var prime_flag = true
      ( 2 to Math.sqrt( num ).toInt ).foreach { i =>
        if( num%i == 0 ) prime_flag = false
      }
      if( prime_flag ) sum += 1
    }
    println( sum )
  }
}