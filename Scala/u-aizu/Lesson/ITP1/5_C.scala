object Main {
  def main(args: Array[String]): Unit = {
    var continue_flag = true
    val pattern = Array( "#", "." )

    while( continue_flag ) {
      val Array( h, w ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }

      if( h == 0 && w == 0 ) continue_flag = false
      else {
        ( 0 until h ).foreach { y =>
          ( 0 until w ).foreach { x =>
            if( y%2 == 0 ) print( pattern( ( x )%2 ) )
            else           print( pattern( ( x + 1 )%2 ) )
          }
          println()
        }
        println()
      }
    }
  }
}