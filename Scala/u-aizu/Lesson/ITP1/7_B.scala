object Main {
  def main(args: Array[String]): Unit = {
    var continue_flag = true

    while( continue_flag ) {
      val Array( n, x ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
      var sum = 0

      if( n == 0 && x == 0 ) continue_flag = false
      else {
        ( 1 to n ).foreach{ i =>
          ( i + 1 to n ).foreach{ j =>
            val k = x - i - j
  
            if( j < k && k <= n ) sum += 1
          } 
        }
        
        println( sum )
      }
    }
  }
}