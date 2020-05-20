object CountDivideNum2
{
  var count              = 0
  val PEOPLE_NUM         = 100
  val MAX_TABLE_CAPACITY = 10

  var memo = Vector.empty :+ (2, 2, 1)

  def main(args: Array[String]): Unit = 
  {
    print( "ans = " + myCheck( PEOPLE_NUM, 2 ).toString + "\n" )
    print( "count = " + count + "\n" )
  }

  def myCheck( remain: Int, pre: Int ): Int =
  {
    count += 1
    var cnt = 0

    // すでに計算済みの値ならば、その値を返す
    memo.foreach { i =>
      count += 1
      if( i._1 == remain && i._2 == pre ) {
        return i._3
      }
    }

    // 2人組が作れなくなったら、割り振り失敗
    if( remain < 0 ) return 0

    //配置する人がいなくなったら、割り振り成功
    if( remain == 0 ) return 1

    ( pre to MAX_TABLE_CAPACITY ).foreach { i =>
      cnt += myCheck( remain - i, i )
    }

    memo = memo :+ ( remain, pre, cnt )
    return cnt
  }
}
