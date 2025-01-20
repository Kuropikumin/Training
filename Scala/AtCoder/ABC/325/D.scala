object D {
  def main( args: Array[String] ): Unit = {
    val Array( l, q ) = scala.io.StdIn.readLine.split( " " ).map{ _.toLong }
    var length_end    = Array( l )
    var sorted_flg    = false

    ( 0 until q.toInt ).foreach{ i =>
      val Array( c, x ) = scala.io.StdIn.readLine.split( " " ).map{ _.toLong }
      if( c == 1L ) {
        length_end = length_end :+ x
        sorted_flg = false
      }
      else {
        if( !sorted_flg ) {
          length_end = length_end.sorted
          sorted_flg = true
        }
        val contain_wood = binarySearch( length_end, x )
        if( contain_wood == 0 ) println( length_end( contain_wood ) )
        else                    println( length_end( contain_wood ) - length_end( contain_wood - 1 ) )
      }
    }
  }

  def binarySearch( list: Array[Long], num: Long ): Int = {
    var left  = 0
    var right = list.length

    while( left <= right ) {
      val middle = ( left + right )/2
      if( middle != 0 ) {
        if( list( middle ) < num ) left = middle + 1
        else {
          if( list( middle - 1 ) < num ) return middle
          else                           right = middle - 1
        }
      }
      else return 0
    }

    return -1 // 見つからない場合の処理
  }
}
