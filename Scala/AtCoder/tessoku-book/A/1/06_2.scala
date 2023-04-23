object Main {
  def main(args: Array[String]): Unit = {
    val Array( period, question_num ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    var total_visitors_list = Vector.fill[Int]( period )( 0 )

    val visitors_list = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    ( 0 until period ).foreach{ i =>
      if( i == 0 ) total_visitors_list = total_visitors_list.updated( i, visitors_list( i ) )
      else         total_visitors_list = total_visitors_list.updated( i, visitors_list( i ) + total_visitors_list( i - 1 ) )
    }

    ( 0 until question_num ).foreach{ i =>
      val Array( start_day, last_day ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
      var answer = 0
      if( start_day == 1 ) answer = total_visitors_list( last_day - 1 )
      else                 answer = total_visitors_list( last_day - 1 ) - total_visitors_list( start_day - 2 )
      println( answer ) 
    }
  }
}
