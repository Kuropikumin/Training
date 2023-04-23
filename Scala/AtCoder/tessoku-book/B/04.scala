object Main {
  def main(args: Array[String]): Unit = {
    val num_2_list = scala.io.StdIn.readLine.split( "" ).map{ _.toInt }
    var answer = 0

    ( 0 until num_2_list.length ).foreach{ i =>
      if( num_2_list( num_2_list.length - ( i + 1 ) ) == 1 ) answer += Math.pow( 2, i ).toInt
    }
    println( answer )
  }
}
