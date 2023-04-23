object Main {
  def main(args: Array[String]): Unit = {
    val check = 100
    val Array( a, b ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    var answer = "No"

    ( a to b ).foreach{ i =>
      if( check%i == 0 ) answer = "Yes"
    }
    println( answer )
  }
}
