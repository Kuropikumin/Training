object C {
  def main( args: Array[String] ): Unit = {
    val num    = scala.io.StdIn.readInt
    val nums1  = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    var result = Array.fill( num )( -1 )
    ( 0 until num ).foreach{ i =>
      val result_index = nums1( i )
      result( result_index - 1 ) = i + 1
    }

    result.foreach{ i => print( i + " " ) }
    println()
  }
}
