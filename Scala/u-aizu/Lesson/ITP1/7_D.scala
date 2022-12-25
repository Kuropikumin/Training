object Main {
  def main(args: Array[String]): Unit = {
    val Array( n, m, l ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    var vecA = Array[Array[Int]]()
    var vecB = Array[Array[Int]]()

    ( 0 until n ).foreach { i =>
      val line = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
      vecA = vecA :+ line
    }

    ( 0 until m ).foreach { i =>
      val line = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
      vecB = vecB :+ line
    }

    calcProduct( vecA, vecB, n, m, l ).foreach{ line => println( line.mkString( " " ) ) }
    
  }

  def calcProduct( a: Array[Array[Int]], b: Array[Array[Int]], n: Int, m: Int, l: Int ): Array[Array[Long]] = {
    var result = Array[Array[Long]]()
    ( 0 until n ).foreach { i =>
      var line = Array[Long]()
      ( 0 until l ).foreach { j =>
        var sum = 0L
        ( 0 until m ).foreach { k =>
          sum += a( i )( k )*b( k )( j )
        }
        line = line :+ sum
      }
      result = result :+ line
    }
    return result
  }
}