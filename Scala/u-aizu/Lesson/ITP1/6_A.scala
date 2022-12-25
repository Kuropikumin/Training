object Main {
  def main(args: Array[String]): Unit = {
    val n = scala.io.StdIn.readInt
    val facs = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    
    var str = ""
    ( 1 until n ).foreach { i =>
      str += facs( n - i ) + " "
    }

    str += facs( 0 )
    println( str )
  }
}