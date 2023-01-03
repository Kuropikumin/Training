object Main {
  def main(args: Array[String]): Unit = {
    val str = scala.io.StdIn.readLine

    str.map{ c =>
      if( c.isLower ) print( c.toUpper )
      else            print( c.toLower )
    }
    println() 
  }
}