object CountDivideNum
{
  var count = 0
  def main(args: Array[String]): Unit = 
  {
    val PEOPLE_NUM         = 100
    print( "ans = " + myCheck( PEOPLE_NUM, 2 ).toString + "\n" )
    print( "count = " + count + "\n" )
  }

  def myCheck( remain: Int, pre: Int ): Int =
  {
    count += 1
    val MAX_TABLE_CAPACITY = 10
    var cnt = 0

    // 2人組が作れなくなったら、割り振り失敗
    if( remain < 0 ) return 0

    //配置する人がいなくなったら、割り振り成功
    if( remain == 0 ) return 1

    ( pre to MAX_TABLE_CAPACITY ).foreach { i =>
      cnt += myCheck( remain - i, i )
    }

    return cnt
  }
}
