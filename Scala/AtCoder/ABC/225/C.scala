object C {
  def main( args: Array[String] ): Unit = {
    val Array( n, m ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    var flag          = true
    var count         = 0
    var first_num     = ""
    var num_pre_str   = ""
    var num_post_int  = 0
    var first_m       = 0

    while( flag && count < n ) {
      val facs = scala.io.StdIn.readLine.split( " " )
      if( count == 0 ) { 
        first_num    = facs( 0 )
        num_pre_str  = first_num.take( first_num.length - 9 )
        num_post_int = first_num.takeRight( 9 ).toInt
        first_m      = surplus7( first_num )
      }

      if( first_m + m > 8 ) flag = false

      ( 0 until m ).foreach{ i =>
        val pre_str  = facs( i ).take( facs( i ).length - 9 )
        val post_int = facs( i ).takeRight( 9 ).toInt
        if( checkStrPlus1( num_pre_str, pre_str ) || post_int != num_post_int + ( count*7 + i ) ) flag = false
      }

      count += 1
    }

    if( flag ) println( "Yes" )
    else       println( "No" )
  }

  def surplus7( str: String ): Int = {
    var count     = 0
    var check_str = str
    var num       = 0
  
    while( check_str != "" ) {
       count += 1
       val check_num = check_str.takeRight( 3 ).toInt
       check_str = check_str.take( check_str.length - 3 )
       if( count%2 == 1 ) num += check_num
       else               num -= check_num
    }

    return ( num%7 + 7 )%7
  }

  def checkStrPlus1( str1: String, str2: String ): Boolean = {
    if( str1 == str2 ) return true
    else {
      var check_str1 = str1
      var check_str2 = str2
      var one_flag   = false
      var nine_flag  = true
      var flag       = true
      while( check_str1 != "" || flag ) {
        if( check_str2.takeRight( 1 ).toInt - check_str1.takeRight( 1 ).toInt == 1 ) {
          if( one_flag ) flag     = false
          else           one_flag = true
        }
        else if( check_str2.takeRight( 1 ).toInt - check_str1.takeRight( 1 ).toInt == -9 ) {
          if( !nine_flag ) flag = false
        }
        else flag = false

        check_str1 = check_str1.take( check_str1.length - 1 )
        check_str2 = check_str2.take( check_str2.length - 1 )
      }

      return flag
    }
  }
}