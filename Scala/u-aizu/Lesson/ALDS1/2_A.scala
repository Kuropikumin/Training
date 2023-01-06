object Main {
  def main( args: Array[String] ): Unit = {
    val list_length = scala.io.StdIn.readInt
    val list        = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    var sorted_list = list
    var change_num  = 0

    ( 0 until list_length ).foreach { i =>
      ( i to 1 by -1 ).foreach{ j =>
        if( sorted_list( j ) < sorted_list( j - 1 ) ) {
          val tmp = sorted_list( j )
          sorted_list( j ) = sorted_list( j - 1 )
          sorted_list( j - 1 ) = tmp
          change_num += 1
        }
      }
    }
    
    println( sorted_list.mkString( " " ) )
    println( change_num )
  }
}