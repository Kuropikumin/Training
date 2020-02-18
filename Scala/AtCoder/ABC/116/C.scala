object Main {
  def main(args: Array[String]): Unit = {
    val factors      = scala.io.StdIn.readLine.split(" ").map{_.toInt}
    var tree_heights = Seq[Int]()
    val start = System.currentTimeMillis

    for(i <- 0 until factors(0)) {
      tree_heights = scala.io.StdIn.readInt +: tree_heights
    }

    val sorted_tree_heights = tree_heights.sorted

    var min_diff = 1000000000
    for(i <- 0 until (factors(0) - factors(1) + 1)) {
      val diff = sorted_tree_heights(i + factors(1) - 1) - sorted_tree_heights(i)
      if (diff < min_diff) min_diff = diff
    }
    println(min_diff)
    println("time : " + ( System.currentTimeMillis - start))
  }
}
