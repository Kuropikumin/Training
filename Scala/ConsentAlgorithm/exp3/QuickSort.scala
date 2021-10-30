object  QuickSort {
    def main( args: Array[String] ): Unit = {
        val test = Array( 5, 3, 9, 4, 1, 2, 8, 7, 6, 3, 4, 8 )
        quickSort( test ).foreach{ print( _ ) }
        println()
    }

    def quickSort( list: Array[Int] ): Array[Int] = {
        if( list.isEmpty || list.length == 1 ) return list
        else {
            val pivot    = list( 0 )
            var large_list = Array.empty[Int]
            var small_list = Array.empty[Int]
            var equal_list = Array.empty[Int]

            list.foreach { i => 
                if( pivot < i )      large_list :+= i
                else if( pivot > i ) small_list :+= i
                else                 equal_list :+= i
            }

            return quickSort( small_list ) ++ equal_list ++ quickSort( large_list )
        }        
    }
}