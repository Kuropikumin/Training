object Main {
  def main(args: Array[String]): Unit = {
    val Array( num, check ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    val num_list = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    var flag = true
    var check_index = num/2

    while( flag ) {
      if( num_list( check_index ) == check ) {
        flag = false
        println( check_index - 1 )
      }
      else if( num_list( check_index ) < check ) {
        check_index -= check_index/2
      }
      else {
        check_index += check_index/2
      }
    }
  }
}
