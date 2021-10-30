object AdvanceLoop {

    var calc_count = 0

    def printExecTime(process: => Unit): Unit = {
        val start = System.currentTimeMillis
        process
        println("処理時間： " + (System.currentTimeMillis - start) + " ミリ秒")
    }

    def main( args: Array[String] ): Unit = {
        val peoples_num = args( 0 ).toInt
        val max_cap     = args( 1 ).toInt

        printExecTime {
            // 2次元表の作成
            var table = Array.fill( peoples_num + 1, max_cap + 1 )( 0 )

            ( 0 to max_cap ).foreach { i =>
                calc_count += 1
                table( 0 )( i ) = 1 
            }

            ( 1 to max_cap ).foreach { cap => 
                ( 2 to peoples_num ).foreach{ people =>
                    calc_count += 1
                    if( ( cap >= 2 ) && ( people >= cap ) ) table( people )( cap ) = table( people - cap )( cap )
                    if( cap > 2 ) table( people )( cap ) += table( people )( cap - 1 )
                }
            }

            println( "People num = " + peoples_num )
            println( "table max cap = " + max_cap )
            println( "total num of combinations = " + table( peoples_num )( max_cap ) )
            println( "calc count = " + calc_count )
        }
    }
}
