object ArrayLength {
    def main( args: Array[String] ): Unit = {
        println( arrayLength( Array( 1, 2, 3, 4, 5) ) )
    }

    def arrayLength( list: Array[Int] ): Int = {
        if( list.isEmpty ) return 0
        else               return 1 + arrayLength( list.init )
    }
}