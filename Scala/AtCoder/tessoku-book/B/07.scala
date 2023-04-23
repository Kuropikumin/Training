import scala.collection.mutable.ArrayBuffer
object Main {
  def main(args: Array[String]): Unit = {
    val end_time     = scala.io.StdIn.readInt()
    val employee_num = scala.io.StdIn.readInt()
    val in_out_list  = Array.fill[Int]( end_time + 1 )( 0 )

    ( 0 until employee_num ).foreach{ i =>
      val Array( in, out ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
      in_out_list( in )  += 1
      in_out_list( out ) -= 1
    }

    val total_employees_list = ArrayBuffer.empty[Int]
    ( 0 until end_time ).foreach { i =>
      var before_employees = 0
      if( i > 0 ) before_employees = total_employees_list( i - 1 )

      total_employees_list += before_employees + in_out_list( i )
    }

    ( 0 until end_time ).foreach{ i =>
      println( total_employees_list( i ) )
    }
  }
}
