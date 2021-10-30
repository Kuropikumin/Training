object SelectSearch {
    def main( args: Array[String] ): Unit = {

        val list = Array( 10, 5, 8, 2, 9, 1 )
        selectSearch( list ).foreach{ i =>
            println( i )
        }
    }

    def selectSearch( list: Array[Int] ): Array[Int] = {
        var result     = new Array[Int]( list.length )
        var other_list = list

        ( 0 until list.length ).foreach{ i => 
            result( i ) = other_list( searchMin( other_list ) )
            other_list  = other_list.filterNot( n => n == result( i ) )
        }

        return result
    }

    def searchMin( list: Array[Int] ): Int = {
        var min       = list( 0 )
        var min_index = 0
        ( 0 until list.length ).foreach{ i =>
            if( min > list( i ) ) {
                min       = list( i )
                min_index = i
            }
        }

        return min_index
    }
}