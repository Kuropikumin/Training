object Main {
  def main( args: Array[String] ): Unit = {
    val Array( n, m ) = scala.io.StdIn.readLine.split( " " ).map{ _.toLong }
    println( gcd( n, m ) )
  }

  def gcd( n: Long, m: Long ): Long = {
    if( n < m ) return gcd( m, n )
    else if( m == 0 || n == 1 ) return n
    else {
      gcd( m, n%m )
    }
  }
}