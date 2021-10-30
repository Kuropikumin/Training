object Sum {
    def main( args: Array[String] ): Unit = {
        println( sum( Array( 5, 4, 3, 2, 1 ) ) )
    }

    def sum( list: Array[Int] ): Int = {
        if     ( list.length == 0 ) return 0
        else if( list.length == 1 ) return list( 0 )
        else                        return list( 0 ) + sum( list.tail )
    }
}