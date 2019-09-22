object Main {
  def main(args: Array[String]): Unit = {
    var cost = 0
    val factors = scala.io.StdIn.readLine.split(" ").map{_.toInt}.sorted

    for(i <- 0 to 1) {
      cost += factors(i + 1) - factors(i)
    }

    println(cost)
  }
}
