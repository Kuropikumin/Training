object Main {
  def main(args: Array[String]): Unit = {
    val Array( num, check ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    val check_list = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    var flag = false;

    check_list.foreach{ i =>
      if( i == check ) flag = true
    }
    if( flag ) println( "Yes" )
    else       println( "No" )
  }
}
