import scala.collection.mutable.ArrayBuffer
object Main {
  def main(args: Array[String]): Unit = {
    val period       = scala.io.StdIn.readInt()
    val visitors_num = scala.io.StdIn.readInt()
    val in_out_list  = Array.fill[Int]( period )( 0 )

    ( 0 until visitors_num ).foreach{ i =>
      val Array( in, out ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
      in_out_list( in - 1 )  += 1
      if( out < period - 1 ) in_out_list( out ) -= 1
    }

    val total_visitors_list = ArrayBuffer.empty[Int]
    ( 0 until period ).foreach { i =>
      var before_visitors = 0
      if( i > 0 ) before_visitors = total_visitors_list( i - 1 )

      total_visitors_list += before_visitors + in_out_list( i )
    }

    total_visitors_list.foreach{ i =>
      println( i )
    }
  }
}
