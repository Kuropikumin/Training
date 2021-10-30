object C {
  def main( args: Array[String] ): Unit = {
    val Array( s, k ) = scala.io.StdIn.readLine.split( " " )
    val result = combination( s ).distinct.sorted
    println( result( k.toInt - 1 ) )
  }

  def combination( str: String ): Array[String] = {
    var result = Array.empty[String] 
    ( 0 until str.length ).foreach { i => 
      val c      = str.charAt( i )
      val other  = str.diff( c.toString )

      if( other.length == 0 ) return Array( c.toString )
      else                    result = result :++ combination( other ).map{ c + _ }
    }
    return result
  }
}
