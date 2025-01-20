object Main {
  def main( args: Array[String] ): Unit = {
    // val queue     = new MyQueue()
    val queue = scala.collection.mutable.Queue[Array[String]]()
    val Array( order_num, quantum ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    var total_time = 0

    ( 0 until order_num ).foreach{ i =>
      queue += scala.io.StdIn.readLine.split( " " )
    }

    while( !queue.isEmpty ) {
      val fac = queue.dequeue()
      val name = fac( 0 )
      var time = fac( 1 ).toInt

      if( time <= quantum ) {
        total_time += time
        println( name + " " + total_time )
      }
      else {
        total_time += quantum
        queue += Array( name, ( time - quantum ).toString )
      }
    }
  }
}