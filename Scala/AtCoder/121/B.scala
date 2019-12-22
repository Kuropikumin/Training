object B {
  def main(args: Array[String]): Unit = {
    val factors       = io.StdIn.readLine().split(" ").map{_.toInt}
    val b_nums        = io.StdIn.readLine().split(" ").map{_.toInt}
    var correct_count = 0

    (0 until factors(0)).foreach { i =>
      val a_nums = io.StdIn.readLine().split(" ").map{_.toInt}
      var ab_sum = 0
      (0 until a_nums.length).foreach { j =>
        ab_sum += a_nums(j)*b_nums(j)
      }
      if(ab_sum + factors(2) > 0) correct_count += 1
    }

    println(correct_count)
  }
}
