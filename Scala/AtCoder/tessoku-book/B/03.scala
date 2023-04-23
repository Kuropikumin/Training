object Main {
  def main(args: Array[String]): Unit = {
    val num = scala.io.StdIn.readInt
    val list = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    var answer = "No"
 
    ( 0 until list.length - 2 ).foreach{ i =>
      ( i + 1 until list.length - 1 ).foreach{ j =>
        ( j + 1 until list.length ).foreach{ k => 
          if( ( list( i ) + list( j ) + list( k ) ) == 1000 ) answer = "Yes"
        }
      }
    }

    println( answer )
  }
}
