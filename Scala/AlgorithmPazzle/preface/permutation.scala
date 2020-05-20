object Permutation
{
  def main( args: Array[String] ): Unit = 
  {
    println( "6_P_3 = " + permutation( 6, 3 ) )
  }

  def permutation( n: Int, r: Int ): Int =
  {
    if( n == r )      return 1
    else if( r == 0 ) return 1
    else              return n*permutation( n - 1, r - 1 )
  }
}
