object Main {
  def main( args: Array[String] ): Unit = {
    val list_length = scala.io.StdIn.readInt
    val list = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    insertionSort( list )
  }

  def insertionSort( list: Array[Int] ): Unit = {
    var result = list
    ( 0 until result.length ).foreach{ i =>
      val v = result( i )
      var change_flag = true
      ( i - 1 to 0 by -1 ).foreach{ j =>
        if( change_flag ) {
          if( result( j ) > v ) {
            result( j + 1 ) = result( j )
            result( j )     = v
          }
          else {
            change_flag = false
          }
        }
      }
      println( result.mkString( " " ) )
    }
  }
}