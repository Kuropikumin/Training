object Main {
  def main(args: Array[String]): Unit = {
    var continue_flag = true

    while( continue_flag ) {
      val Array( h, w ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }

      if( h == 0 && w == 0 ) continue_flag = false
      else {
        ( 0 until h ).foreach { y =>
          println( "#"*w )
        }
        println()
      }
    }
  }
}