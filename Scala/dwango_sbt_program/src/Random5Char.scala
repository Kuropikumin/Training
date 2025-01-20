object Random5Char {
    def main( args: Array[String] ): Unit = {
        ( 1 to 1000 ).foreach { i =>
            // val str = new scala.util.Random(new java.security.SecureRandom()).alphanumeric.take(5).toList match {
            val str = List( "a", "a", "b", "c", "d" ) match {
                case List( a, b, c, d, _ ) => List( a, b, c, d, a ).mkString
                case _ => "error string"
            }
            print( i + " : " )
            println( str )
        }
    }
}
