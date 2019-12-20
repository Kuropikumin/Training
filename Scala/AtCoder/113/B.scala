object Main {
  def main(args: Array[String]): Unit = {
    val candidate_num = scala.io.StdIn.readInt
    val temperatures  = scala.io.StdIn.readLine.split(" ").map{_.toInt}
    val candidate     = scala.io.StdIn.readLine.split(" ").map{_.toInt}
    var diff_min      = 100000.0
    var dicision_num  = 0

    for(i <- 0 until candidate.length) {
      val diff = Math.abs(temperatures(1) - (temperatures(0) - 0.006*candidate(i)))
      if (diff_min > diff) {
        diff_min     = diff
        dicision_num = i + 1
      }
    }
    println(dicision_num)
  }
}
