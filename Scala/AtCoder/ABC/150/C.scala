object C {
  def main(args: Array[String]): Unit = {
    val num          = io.StdIn.readInt
    var num1         = io.StdIn.readLine.split(" ").map{_.toInt}
    var num2         = io.StdIn.readLine.split(" ").map{_.toInt}
    var upstairs_num = Vector.empty[Int]
    (1 to 7).foreach { i =>
      if (i == 1) upstairs_num = upstairs_num :+ i
      else        upstairs_num = upstairs_num :+ i*upstairs_num(i - 2)
    }

    var num1_count, num2_count = 0

    (0 until num).foreach { i =>
      num1_count += upstairs_num(7 - num + i)*num1.filter(x => x < num1(i)).length
      num2_count += upstairs_num(7 - num + i)*num1.filter(x => x < num2(i)).length

      num1 = num1.filterNot(_ == num1(i))
      num2 = num2.filterNot(_ == num2(i))
    }

    println(Math.abs(num1_count - num2_count) + 1)
  }
}
