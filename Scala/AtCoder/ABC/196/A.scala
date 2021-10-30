object A {
  def main(args: Array[String]): Unit = {
    val Array( a, b ) = io.StdIn.readLine.split( " " ).map{ _.toInt }
    val Array( c, d ) = io.StdIn.readLine.split( " " ).map{ _.toInt }
    println( b - c )
  }
}
