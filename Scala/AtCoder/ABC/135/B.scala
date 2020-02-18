object B {
  def main(args: Array[String]): Unit = {
    val factor_num   = scala.io.StdIn.readInt
    val factors      = scala.io.StdIn.readLine.split(" ").map{_.toInt}
    val sort_factors = factors.sorted

    var difference_num = 0

    (0 until factors.length).foreach { i =>
      if(factors(i) != sort_factors(i)) difference_num += 1
    }

    if(difference_num <= 2) println("YES")
    else                    println("NO")

  }
}
