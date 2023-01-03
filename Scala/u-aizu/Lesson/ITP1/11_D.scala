object Main {
  def main( args: Array[String] ): Unit = {
    var same_flag = false

    val dice_num = scala.io.StdIn.readInt
    var dice_num_list = Array[ Array[Int] ]()

    ( 0 until dice_num ).foreach{ i =>
      dice_num_list = dice_num_list :+ scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    }
    
    ( 0 until dice_num - 1   ).foreach { i =>
      ( i + 1 until dice_num ).foreach { j =>
        val dice_i = new Dice( dice_num_list( i ) )
        val dice_j = new Dice( dice_num_list( j ) )
        if( dice_i.isEqual( dice_j ) ) same_flag = true
      }
    }

    if( same_flag ) println( "No" )
    else            println( "Yes" )
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
      if( this.list( 2 ) == d.findSideNum( this.list( 0 ), this.list( 1 ) ) ) {
        if( this.list( 3 ) == d.list( 3 ) 
            && this.list( 4 ) == d.list( 4 )
            && this.list( 5 ) == d.list( 5 ) ) return true
        else                                   return false
      }
      else return false
    }
  }
}