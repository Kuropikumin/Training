object B {
  def main(args: Array[String]): Unit = {
    val str = Scala.io.StdIn.readLine
    var flg = true
    for( c <- str ) {
      if( c == "." ) flg = false
      if( flg ) print( c )
    }
    println( "" )
  }
}
