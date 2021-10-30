object B {
  def main( args: Array[String] ): Unit = {
    var input = io.StdIn.readLong
    var count = 0

    while( input >= 2 ) {
      count += 1
      input /= 2
    }

    println( count )
  }
}
