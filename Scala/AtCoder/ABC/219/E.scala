object E {
  def main(args: Array[String]): Unit = {
    val a_num = scala.io.StdIn.readInt
    var a_t_array = Array[Int, Int]()
    for( i <- ( 0 until a_num ) ) {
      a_t_array = a_t_array :+ scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    }
    val q_num = scala.io.StdIn.readInt
    var x_array = Array[Int]()
    for( i <- ( 0 until a_num ) ) {
      x_array = x_array :+ scala.io.StdIn.readInt
    }

    var answer = Array[Long]()

    println( a_num + " : " q_num )
    for( i <- ( 0 until a_num ) ) println( i + " : " a_t_array( i ) )
    for( i <- ( 0 until q_num ) ) println( i + " : " x_array( i ) )
  }
}
