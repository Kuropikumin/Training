object Factorial {
    def main( args: Array[String] ): Unit = {
        println( factorial( 5 ) )
    }

    def factorial( num: Int ): Int = {
        if( num == 0 || num == 1 ) return 1
        else                       return num*factorial( num - 1 )
    }
}