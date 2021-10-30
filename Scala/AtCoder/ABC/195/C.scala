object C {
  def main(args: Array[String]): Unit = {
    val num         = io.StdIn.readLong
    var total_comma = 0L
    var target = num
    var count = 0

    while( target >= 1000 ) {
      count += 1
      target = target/1000L
    }

    ( 0 until count ).foreach{ i =>
      total_comma += num - Math.pow( 1000L, i + 1 ).toLong + 1
    }

    println( total_comma )
  }
}
