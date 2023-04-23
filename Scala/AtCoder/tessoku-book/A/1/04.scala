object Main {
  def main(args: Array[String]): Unit = {
    val num_10 = scala.io.StdIn.readInt
    val answer_length = 10
    val answer = Array.fill( answer_length )( 0 )

    var calc_num = num_10
    var count    = 0
    while( calc_num > 0 ) {
      count += 1
      if( calc_num%2 == 1 ) answer( answer_length - count ) = 1
      calc_num = calc_num/2
    }

    println( answer.mkString( "" ) )
  }
}
