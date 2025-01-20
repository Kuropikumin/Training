object CheckRightTriangle {
    def main( args: Array[String] ): Unit = {
        println( "( a, b, c ) = ")
        for( a <- 1 to 1000; b <- 1 to 1000; c <- 1 to 1000 ) {
            val max = List( a, b, c ).max
            if( !( ( a + b + c - max ) < max ) ) {
                if( checkRightTriangle( a, b, c) ) {
                    println( ( a, b, c ) )
                }
            }
        }
    }

    def checkRightTriangle( a: Int, b: Int, c: Int ): Boolean = {
        val nums = List( a, b, c ).sorted
        var flag = false
        if( Math.pow( nums( 2 ), 2 ).toInt == Math.pow( nums( 0 ), 2 ).toInt + Math.pow( nums( 1 ), 2 ).toInt ) flag = true
        return flag
    }
}
