object Dijkstra {
    def main( args: Array[String] ): Unit = {
        val graph = Map (
            "start" -> Map( "a"   -> 6, "b"   -> 2 ),
            "a"     -> Map( "fin" -> 1 ),
            "b"     -> Map( "a"   -> 3, "fin" -> 5 ),
            "fin"   -> Map.empty[String, Int]
        )

        println( dijkstra( graph, "a", "b" ) )
    }

    def dijkstra( matrix: Map[ String, Map[String, Int] ], start_node: String, goal_node: String ): Int = {
        var costs_list   = Map.empty[String, Int]
        var parents_list = Map.empty[String, String]
        var process_node = Array.empty[String]
        var check_node   = ""

        // 初期化
        matrix.keys.foreach{ key =>
            costs_list   += ( key -> Int.MaxValue )
            parents_list += ( key -> "start" )
        }

        // 出発点の情報更新
        costs_list += ( start_node -> 0 )
        check_node  = findLowestCostNode( costs_list, process_node )

        // ダイクストラ法によるノードのコスト表更新処理
        // check_nodeが存在するならば繰り返す
        while( check_node != "" ) {
            println( "check node: " + check_node )
            val cost      = costs_list( check_node )
            val neighbors = matrix( check_node ).keys 
            neighbors.foreach{ key =>
                val new_cost = cost + matrix( check_node )( key )
                if( new_cost < costs_list( key ) ) {
                    costs_list   += ( key -> new_cost )
                    parents_list += ( key -> check_node )
                }
            }

            process_node :+= check_node
            check_node     = findLowestCostNode( costs_list, process_node )
        }

        if( costs_list( goal_node) == Int.MaxValue ) {
            println( "Not Found route from " + start_node + " to " + goal_node )
            return -1
        }
        
        printRoute( start_node, goal_node, parents_list )
        return costs_list( goal_node )
    }

    def findLowestCostNode( list: Map[String, Int], checked_list: Array[String] ): String = {
        var node_name = ""
        var cost      = Int.MaxValue

        list.keys.foreach{ key => 
            if( cost > list( key ) && !checked_list.contains( key ) ) {
                node_name = key
                cost      = list( key )
            }
       }

       return node_name
    }

    def printRoute( start_node: String, goal_node: String, parents_list: Map[String, String] ): Unit = {
        var check_node = goal_node
        var routes     = Array.empty[String]
        while( check_node != start_node ) {
            routes     :+= check_node
            check_node   = parents_list( check_node )
        }

        print( start_node + " -> ")
        routes.reverse.foreach{ node => 
            if( node == goal_node ) println( node )
            else                    print( node + " -> ")
        }
    }
}