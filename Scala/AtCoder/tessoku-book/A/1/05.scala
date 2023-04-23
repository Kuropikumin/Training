object Main {
  def main(args: Array[String]): Unit = {
    val Array( max_num, check ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    var count = 0

    ( 1 to max_num ).foreach{ i => 
      ( 1 to max_num ).foreach{ j =>
        val last_num = check - i - j
        if( 0 < last_num && last_num <= max_num ) count += 1
      }
    }

    println( count )
  }
}
