object A {
  def main( args: Array[String] ): Unit = {
    val input   = io.StdIn.readLine.split( "" ).distinct
    val input_l = input.length 
    if     ( input_l == 1 ) println( 1 )
    else if( input_l == 2 ) println( 3 )
    else if( input_l == 3 ) println( 6 )
  }
}