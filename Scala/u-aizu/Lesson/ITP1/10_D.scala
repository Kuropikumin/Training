object Main {
  def main( args: Array[String] ): Unit = {
    val dimention = scala.io.StdIn.readInt
    val x         = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    val y         = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }

    println( calcDistance( x, y, 1 ) )
    println( calcDistance( x, y, 2 ) )
    println( calcDistance( x, y, 3 ) )
    println( calcDistance( x, y, 0 ) )
  }

  def calcDistance( x: Array[Int], y: Array[Int], n: Int ): Double = {
    var dis = 0d
    if( n == 0 ) {
      ( 0 until x.length ).foreach{ i =>
        val c_dis = Math.abs( x( i ) - y( i ) )
        if( dis < c_dis ) dis = c_dis
      }
    }
    else {
      ( 0 until x.length ).foreach{ i =>
        dis += Math.pow( Math.abs( x( i ) - y( i ) ), n )
      }
      dis = Math.pow( dis, 1d/n )
    }
    return dis
  }
}