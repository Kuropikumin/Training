object B {
  def main(args: Array[String]): Unit = {
    val factors    = io.StdIn.readLine.split(" ").map{_.toInt}
    val each_test  = io.StdIn.readLine.split(" ").map{_.toInt}
    val goal_point = factors(2)*factors(0)
    var now_point  = 0

    each_test.foreach { i =>
      now_point += i
    }

    var diff_point = goal_point - now_point
    if (diff_point < 0) diff_point = 0

    if(diff_point > factors(1)) {
      println(-1)
    }
    else {
      println(diff_point)
    }
  }
}
