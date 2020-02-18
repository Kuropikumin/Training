object E {
  def main(args: Array[String]): Unit = {
    val Array(num_length, comb_num) = io.StdIn.readLine.split(" ").map{_.toInt}
    val nums = io.StdIn.readLine.split(" ").map{_.toInt}.sorted
    var sum = 0L

    (0 until num_length).foreach { i =>
      (i until num_length).foreach { j =>
        if(j - i >= comb_num) {
          sum += (nums(j) - num(i))*(comb(j - i, comb_num)) % 1000000007L
        }
      }
    }
  }

  def comb(x: Int, y: Int): Long {
    var num = 1.0

    (0 until y).foreach { i =>
      num *= (x - i)/(i + 1).toDouble
    }

    return num.toLong
  }
}
