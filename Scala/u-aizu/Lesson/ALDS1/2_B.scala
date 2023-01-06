object Main {
  def main( args: Array[String] ): Unit = {
    val list_length = scala.io.StdIn.readInt
    val list        = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    var sorted_list = list
    var change_num  = 0

    ( 0 until list_length ).foreach { i =>
      var change_element = i
      ( i until list_length ).foreach{ j =>
        if( sorted_list( j ) < sorted_list( change_element ) ) {
          change_element = j          
        }
      }
      if( change_element != i ) {
        val tmp = sorted_list( i )
        sorted_list( i ) = sorted_list( change_element )
        sorted_list( change_element ) = tmp
        change_num += 1
      }
    }
    
    println( sorted_list.mkString( " " ) )
    println( change_num )
  }
}