object B {
  def main( args: Array[String] ): Unit = {
    val n_num      = io.StdIn.readInt
    var n_edge_num = Array.fill( n_num )( 0 )
    var count = 0

    while( count < n_num - 1 ) {
      val facs = io.StdIn.readLine.split( " " ).map{ _.toInt - 1 }
      n_edge_num( facs( 0 ) ) += 1
      n_edge_num( facs( 1 ) ) += 1
      count += 1
    }

    var flag = false
    n_edge_num.foreach{ i =>
      if( i == n_num - 1 ) flag = true
    }

    if( flag ) println( "Yes" )
    else       println( "No" )
  }
}
