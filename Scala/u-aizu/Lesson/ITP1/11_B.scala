object Main {
  def main( args: Array[String] ): Unit = {
    val start_list = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    val check_num  = scala.io.StdIn.readInt

    ( 0 until check_num ).foreach{ i =>
      val Array( top, front ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
      val dice = new Dice( start_list )
      println( dice.findSideNum( top, front ) )
    }
  }
}

class Dice( var list: Array[Int] ) {
  def play( order: String ): Unit = {
    order match {
      case "N" => list = Array( list( 1 ), list( 5 ), list( 2 ), list( 3 ), list( 0 ), list( 4 ) )
      case "W" => list = Array( list( 2 ), list( 1 ), list( 5 ), list( 0 ), list( 4 ), list( 3 ) )
      case "S" => list = Array( list( 4 ), list( 0 ), list( 2 ), list( 3 ), list( 5 ), list( 1 ) )
      case "E" => list = Array( list( 3 ), list( 1 ), list( 0 ), list( 5 ), list( 4 ), list( 2 ) )
    }
  }

  def ternLeft(): Unit = {
    list = Array( list( 0 ), list( 2 ), list( 4 ), list( 1 ), list( 3 ), list( 5 ) )
  }
  def ternRight(): Unit = {
    list = Array( list( 0 ), list( 3 ), list( 1 ), list( 4 ), list( 2 ), list( 5 ) )
  }

  def findSideNum( top: Int, front: Int ): Int = {
    this.list.indexOf( top ) match {
      case 1 => this.play( "N" )
      case 2 => this.play( "W" )
      case 3 => this.play( "E" )
      case 4 => this.play( "S" )
      case 5 => { this.play( "S" ); this.play( "S" ) }
      case _ => {}
    }
    this.list.indexOf( front ) match {
      case 2 => this.ternLeft()
      case 3 => this.ternRight()
      case 4 => { this.ternRight(); this.ternRight() }
      case _ => {}
    }

    return list( 2 )
  }
}