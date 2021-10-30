object BreadthFirstSearch {
    def main( args: Array[String] ): Unit = {
        val person_matrix = Map(
            "you"    -> Array( "alice", "bob", "claire" ),
            "bob"    -> Array( "anuj", "peggy" ),
            "alice"  -> Array( "peggy" ),
            "claire" -> Array( "thom", "jonny" ),
            "anuj"   -> Array.empty[String],
            "peggy"  -> Array.empty[String],
            "thom"   -> Array.empty[String],
            "jonny"  -> Array.empty[String]
        )

        println( breadthFirstSearch(person_matrix, "you") )
    }

    def breadthFirstSearch( matrix: Map[String, Array[String]], first_node: String ): Int = {
        var check_queue   = matrix( first_node )
        var searched_node = Array( first_node )
        var pass_num      = 0

        if( checkGoal( first_node) ) return pass_num

        while( !check_queue.isEmpty ) {
            pass_num += 1
            var next_search_queue = Array.empty[String]

            check_queue.foreach {check_node =>
               
                if( checkGoal( check_node ) ) return pass_num
            
                next_search_queue = next_search_queue :++ matrix( check_node ) 
                searched_node     :+= check_node
            }

            check_queue = next_search_queue.filter{ !searched_node.contains( _ ) }
        }

        return -1
    }

    def checkGoal( name: String ): Boolean = {
        if( name == "bob" ) return true
        else                 return false
    }
}