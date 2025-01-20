object CalcScala {
  def main( args: Array[String] ) {
    var count = 0
    var ans   = 1.0.toDouble

    while( count < 10000 ) {
      if( count%100 == 0 ) print( count + " : " + ans*4 + "\n" )
      count += 1
      val code = ( count%2 )*2 - 1 // 奇数ならマイナス、偶数ならプラス
      ans   -= code.toDouble/(count*2 + 1 ).toDouble
    }
  }

  def calcLeibniz( pre_num: Double, num: Int ) {
    val code        = ( num%2 )*2 - 1 // 奇数ならマイナス、偶数ならプラス
    val denominator = num*2 + 1
    val ans         = pre_num + ( code.toDouble/denominator.toDouble )

    if( num == 0 ) return ans
    else           return calcLeibniz( ans, num - 1 )
  }
}
