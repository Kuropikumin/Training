object C {
  def main(args: Array[String]): Unit = {
    val num              = scala.io.StdIn.readLong
    val number_of_digits = num.toString.length
    val digits_harf      = number_of_digits/2
    var count = 0L

    if( number_of_digits%2 == 1 ) {
      println( ( Math.pow( 10, digits_harf ) - 1 ).toInt )
    }
    else {
      val num_top    = num.toString.take( digits_harf ).toLong
      val num_bottom = num.toString.takeRight( digits_harf ).toLong

      if( num_top <= num_bottom ) {
        println( num_top )
      }
      else {
        println( num_top - 1 )
      }
    }
  }
}
