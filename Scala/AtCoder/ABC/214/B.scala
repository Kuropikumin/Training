object B {
  def main( args: Array[String] ): Unit = {
    val Array( s, t )        = io.StdIn.readLine.split( " " ).map{ _.toInt }
    var answer = 0
    ( 0 to s ).foreach { i => 
      ( 0 to s ).foreach { j => 
        ( 0 to s ).foreach { k => 
          if( i + j + k <= s && i*j*k <= t ) answer += 1
        }
      }
    }

    println( answer )
  }
}
