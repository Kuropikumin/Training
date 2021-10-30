object Greedy {
    def main( args: Array[String] ): Unit = {
        // 初期データ
        // 貪欲法では、データに重複があるとだめなので、重複排除を念のため行う
        val stations = Map(
            "kone"   -> Set( "id", "nv", "ut" ),
            "ktwo"   -> Set( "wa", "id", "mt" ),
            "kthree" -> Set( "or", "nv", "ca" ),
            "kfour"  -> Set( "nv", "ut" ),
            "kfive"  -> Set( "ca", "az" ) 
        )
        val need_stations = Set( "mt", "wa", "or", "id", "nv", "ut", "ca", "az" )

        println( greedy( stations, need_stations ) )
    }

    def greedy( list: Map[String, Set[String]], need_stations: Set[String] ): Set[String] = {
        var result          = Set.empty[String]
        var coverd_stations = Set.empty[String]
        var flag            = true              // 無限ループ防止用

        while( coverd_stations != need_stations && flag ) {
            val best_station = pickUpBestStation( list, need_stations -- coverd_stations )

            // 空集合の場合、これ以上処理が進まない（解が存在しない）ので処理を中止する
            if( best_station == "" ) flag = false

            coverd_stations ++= list( best_station )
            result           += best_station
        }

        if( !flag ) {
            println( "Answer is Not Found !!! ")
            return Set.empty[String]
        }

        return result
    }

    def pickUpBestStation ( list: Map[String, Set[String]], not_enough_stations: Set[String] ): String = {
        var name           = ""
        var max_coverd_num = 0

        list.keys.foreach { key =>
            val coverd = list( key ) & not_enough_stations
            if( coverd.size > max_coverd_num ) {
                name           = key
                max_coverd_num = coverd.size
            }
        }

        return name
    }
}