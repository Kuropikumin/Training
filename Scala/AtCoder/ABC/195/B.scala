object B {
  def main(args: Array[String]): Unit = {
    val Array( orange_min, orange_max, total_weight ) = io.StdIn.readLine.split( " " ).map{ _.toInt }
    val target_weight = total_weight*1000


    val max_select_num = target_weight/orange_min
    val min_select_num = if( target_weight%orange_max == 0 ) target_weight/orange_max else target_weight/orange_max + 1

    if( max_select_num > min_select_num ) println( min_select_num + " " + max_select_num )
    else {
      if( max_select_num*orange_max < target_weight ) println( "UNSATISFIABLE" )
      else                                            println( min_select_num + " " + max_select_num )
    }
  }
}
