object C {
  def main( args: Array[String] ): Unit = {
    val factors   = io.StdIn.readLine.split( " " ).map{ _.toLong }
    var factors_H = Array( factors( 2 ).toInt ).fill( 0L )
    var factors_W = Array( factors( 2 ).toInt ).fill( 0L )

    ( 0 until factors( 2 ).toInt ).foreach{ i =>
      val Array( h, w ) = io.StdIn.readLine.split( " " ).map{ _.toLong }
      factors_H( i ) = h
      factors_W( i ) = w
    }
 
    val factors_H_sort = factors_H.toSeq.sorted
    val factors_W_sort = factors_W.toSeq.sorted

    ( 0 until factors( 2 ).toInt ).foreach{ i =>
      println( binarySearch( factors_W_sort, factors_W( i ) ) + " : " + binarySearch( factors_H_sort, factors_H( i ) ) )
    }
  }

  def binarySearch( list: Array[Long], result: Int ): Int = {
    var first = -1
    var last  = list.length - 1
    var count = 0
    var mid   = 0

    while( last - first > 1 ) {
      mid = first + ( last - first )/2
      if( result == list( mid ) ) {
        println( "result : " + result + ", count : " + count )
        return mid
      }
      else if( result < list( mid ) ) last  = mid
      else                            first = mid
      count += 1
    }

    if( result == list( last ) ) {
      println( "result : " + result + ", count : " + count )
      return last
    }
    println( "not found : " + result + ", count : " + count )
    return -1
  }
}
