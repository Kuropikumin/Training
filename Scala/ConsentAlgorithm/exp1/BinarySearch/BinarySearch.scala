object BinarySearch {
  def main(args: Array[String]): Unit = {
      val arr = Array.range( 1, 129 ) :+ 3000 
      arr.foreach { i => 
          binarySearch( arr, i )
      }
      binarySearch( arr, 129 )
  }

  def binarySearch( list: Array[Int], result: Int ): Int = {
      var low   = 0
      var high  = list.length
      var count = 0
      
      while( low <= high ) {
          val mid       = ( low + high )/2
          val check_num = list( mid )
          if( check_num == result ) {
              println( "result : " + result + ", count : " + count ) 
              return mid
          }
          count += 1
          
          if( check_num < result )      low  = mid + 1
          else if( check_num > result ) high = mid - 1
      }

      println( "result : " + result + " is Not Found, count : " + count ) 
      return -1
  }
}
