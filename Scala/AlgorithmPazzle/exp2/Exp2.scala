object Exp2 {
  def main(args: Array[String]): Unit = {
    val station_nums        = 29
    val finish_station_num  = 17

    var comb_num = 0
    
    // 順廻り
    comb_num += Math.pow( 2, finish_station_num - 2 ).toInt
    
    // 逆回り
    comb_num += Math.pow( 2, Math.abs( finish_station_num - station_nums ) ).toInt
    println( comb_num - 1 )
  }
}
