object Main {
  val pattern = Map( "S" -> 0, "H" -> 1, "C" -> 2, "D" -> 3 )
  val pattern_card_nums = 13
  def main(args: Array[String]): Unit = {
    val card_num = scala.io.StdIn.readInt
    var card_list = ( 0 to 51 ).toArray
    ( 0 until card_num ).foreach { i =>
      val Array( p, n ) = scala.io.StdIn.readLine.split( " " )
      card_list = card_list.filterNot( _ == card2Num( p, n.toInt - 1 ) )
    }

    card_list.foreach { i =>
      val missing_card = num2Card( i )
      println( missing_card( 0 ) + " " + ( missing_card( 1 ).toInt + 1 ) )
    }
  }

  def num2Card( n: Int ): Array[String] = {
    val rpattern = for( ( k, v ) <- pattern ) yield( v, k )
    return Array( rpattern( n/pattern_card_nums ), ( n%pattern_card_nums ).toString )
  }

  def card2Num( p: String, n: Int ): Int = {
    return pattern( p )*pattern_card_nums + n
  }
}