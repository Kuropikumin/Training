object Main {
  val build_num = 4
  val floor_num = 3
  val room_num  = 10
  def main(args: Array[String]): Unit = {
    var peoples_list = Array.fill[Int]( build_num, floor_num, room_num )( 0 )
    val change_num = scala.io.StdIn.readInt

    ( 0 until change_num ).foreach { i =>
      val Array( b, f, r, v ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
      peoples_list( b - 1 )( f - 1 )( r - 1 ) += v
    }

    printPeoplesList( peoples_list )
  }

  def printPeoplesList( list: Array[Array[Array[Int]]] ): Unit = {
    ( 0 until build_num ){ b =>
      list( b ).foreach { f =>
        println( f.mkString( " " ) ) 
      }
      if( b < 3 ) println( "#"*20 )
    }
  }
}