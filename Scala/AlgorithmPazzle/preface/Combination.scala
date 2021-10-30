object Combination {
    
    var calc_count = 0
    var memo       = Array.empty[Array[Int]]

    def printExecTime(process: => Unit): Unit = {
        val start = System.currentTimeMillis
        process
        println("処理時間： " + (System.currentTimeMillis - start) + " ミリ秒")
    }

    def main( args: Array[String] ): Unit = {
        val n = args( 0 ).toInt
        val r = args( 1 ).toInt

        memo = Array.fill( n + 1, r + 1 )( - 1)

        printExecTime {
            println( n + "C" + r + " = " + combination( n, r ) )
            println( "calc count = " + calc_count )
        }
    }

    def combination( n: Int, r: Int ): Int = {
        calc_count += 1
        if( n < r || n <= 0 ) {
            println( "Usage: scala combination.scala n r" )
            println( " n > 0, r >= 0, n >= r" )
            sys.exit( 1 )
        }

        if( r == 0 || n == r)           return 1
        else if( r == 1 )               return n
        else if( memo( n )( r ) != -1 ) return memo( n )( r )
        else {
            val ans = combination( n - 1, r ) + combination( n - 1, r - 1 )
            memo( n )( r ) = ans
            return ans
        }
    }
}