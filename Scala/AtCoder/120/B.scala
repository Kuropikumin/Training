object B {
  def main(args: Array[String]): Unit = {
    val nums            = io.StdIn.readLine().split(" ").map{_.toInt}
    val divide_max_num  = if(nums(0) < nums(1)) nums(0) else nums(1)
    var divisible_nums = Vector.empty[Int]

    (0 until divide_max_num).foreach { i =>
      val divide_num = divide_max_num - i
      if(nums(0)%divide_num == 0 &&
         nums(1)%divide_num == 0) {
        divisible_nums = divisible_nums :+ divide_num
      }
    }
    val print_number = nums(2) - 1
    divisible_nums.foreach { println(_)}
    println(print_number)
    if(print_number < 0) {
      println(1)
    }
    else {
      println(divisible_nums(print_number))
    }
  }
}
