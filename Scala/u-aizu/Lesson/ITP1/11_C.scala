object Main {
  def main( args: Array[String] ): Unit = {
    val a_list = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    val b_list = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }

    val dice_a = new Dice( a_list )
    val dice_b = new Dice( b_list )

    if( dice_a.isEqual( dice_b) ) println( "Yes" )
    else                          println( "No")
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

  def isEqual( d: Dice ): Boolean = {
    // listの中身が違う場合
    if( !this.list.sorted.sameElements( d.list.sorted ) ) {
      return false
    }
    else {
      if( this.list( 2 ) == d.findSideNum( this.list( 0 ), this.list( 1 ) ) ) return true
      else                                                                    return false
    }
  }
}