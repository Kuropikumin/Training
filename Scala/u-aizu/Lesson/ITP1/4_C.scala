object Main {
  def main(args: Array[String]): Unit = {
    val r = scala.io.StdIn.readDouble
    val s = r*r*Math.PI
    val c = 2*r*Math.PI

    println( toPlainString( s, 6 ) + " "  + toPlainString( c, 6 ) )
  }

  def toPlainString( n: Double, significant_digits: Int ): String = {
    val integer = n.toLong
    val decimal = Math.round( ( n - integer )*Math.pow( 10, significant_digits ) )

    val integer_s = integer.toString()
    var decimal_s = decimal.toString()

    if( decimal_s.length < significant_digits ) {
      decimal_s = "0"*( significant_digits - decimal_s.length ) + decimal_s
    }

    return integer_s + "." + decimal_s
  }
}
