object Main {
  def main(args: Array[String]): Unit = {
    val nums     = scala.io.StdIn.readLine.split("")
    val like_num = 753
    var min_diff = 1000000
    for(i <- 0 until nums.length - 2) {
      val num = (nums(i) + nums(i + 1) + nums(i + 2)).toInt
      val diff = Math.abs(like_num - num)
      if( min_diff > diff) {
        min_diff = diff
      }
    }
    println(min_diff)
  }
}
