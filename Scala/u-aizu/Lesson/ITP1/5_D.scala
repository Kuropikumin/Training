object Main {
  def main(args: Array[String]): Unit = {
    val n = scala.io.StdIn.readInt
    print3( n )
  }

  def print3( num: Int ): Unit = {
    var s = "";
    ( 1 to num ).foreach { i =>
      val num3 = i.toString.split( "" ).map{ _.toInt }.filter( n => n == 3 ).length
      if( i%3 == 0 ) {
        s += " " + i.toString()
      }
      else if( num3 > 0 ) {
        s += " " + i.toString()
      }
    }

    println( s )
  }
}