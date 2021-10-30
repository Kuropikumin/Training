object Recursion {
    def main( args: Array[String] ): Unit = {
        recursion( 4 )
    }

    def recursion( start_num: Int ): Unit = {
        if( start_num <= 0 ) println( "Go!" )
        else {
            print( start_num + "..." )
            recursion( start_num - 1 )
        }
    }
}