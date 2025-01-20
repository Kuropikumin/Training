object Main {
  def main( args: Array[String] ): Unit = {
    var list        = scala.collection.mutable.ArrayBuffer.empty[Int]
    val list_length = scala.io.StdIn.readInt

    ( 0 until list_length ).foreach{ i =>
      val n = scala.io.StdIn.readInt
      list += n
    }
    
    shellSort( list ).foreach{ i =>
      println( i )  
    }
  }

  def insertionSort( list: scala.collection.mutable.ArrayBuffer[Int], g: Int ): Long = {
    var cnt = 0L
    
    ( g until list.length ).foreach { i =>
      val v = list( i )
      var j = i - g
      while( 0 <= j && list( j ) > v ) {
        list( j + g ) = list( j )
        j             = j - g
        cnt          += 1
      }
      list( j + g ) = v
    }
    return cnt
  }

  def shellSort( list: scala.collection.mutable.ArrayBuffer[Int] ): scala.collection.mutable.ArrayBuffer[Int] = {
    var cnt = 0L
    val g   = createGArray( list.length )
    println( g.length )
    println( g.mkString( " " ) )

    g.foreach{ i =>
      cnt += insertionSort( list, i )  
    }

    println( cnt )
    return list
  }

  def createGArray( num: Int ): Array[Int] = {
    var n = 1
    var count = 1
    var g = Array[Int]()

    while( n < num ) {
      g = n +: g
      count += 1
      n = ( Math.pow( 3, count ).toInt - 1 )/2
    }

    if( g.isEmpty ) g = Array( 1 )
    return g
  }
}