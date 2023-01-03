object Main {
  def main( args: Array[String] ): Unit = {
    val dice = new Dice( scala.io.StdIn.readLine.split( " " ).map{ _.toInt } )
    val order_list = scala.io.StdIn.readLine.split( "" )
    order_list.foreach{ i =>
      dice.play( i )
    }

    println( dice.list( 0 ) )
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
}