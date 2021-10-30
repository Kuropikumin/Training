object AdvanceMemo {

    var calc_count = 0
    // メモの導入
    var combination_num = Array.empty[ Array[ Int ] ]
    def printExecTime(process: => Unit): Unit = {
        val start = System.currentTimeMillis
        process
        println("処理時間： " + (System.currentTimeMillis - start) + " ミリ秒")
    }

    def main( args: Array[String] ): Unit = {
        val peoples_num = args( 0 ).toInt
        val max_cap     = args( 1 ).toInt

        // メモの初期化
        combination_num = Array.fill( peoples_num, max_cap )( -1 )

        printExecTime {
            println( "People num = " + peoples_num )
            println( "table max cap = " + max_cap )
            println( "total num of combinations = " + countDivideNum( peoples_num, max_cap, 2 ) )
            println( "calc count = " + calc_count )
        }
    }

    def countDivideNum( peoples_num: Int, max_cap: Int, pair_people: Int ): Int = {
        calc_count += 1
        var count = 0
        if      ( peoples_num == 0 )          return 1 // 割り振りに成功した場合
        else if ( peoples_num < pair_people ) return 0 // 割り振りに失敗した場合
        // 上記以外の再帰処理
        else {
            if( combination_num( peoples_num - 1 )( pair_people - 1 ) != -1 ) return combination_num( peoples_num - 1 )( pair_people - 1 )

            ( pair_people to max_cap ).foreach { i =>
                count += countDivideNum( peoples_num - i, max_cap, i )
            }
        }

        combination_num( peoples_num - 1 )( pair_people - 1 ) = count
        return count
    }
}