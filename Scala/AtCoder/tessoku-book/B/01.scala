object Main {
  def main(args: Array[String]): Unit = {
    val Array( a, b ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    println( a + b )
  }
}
