object Main {
  def main(args: Array[String]): Unit = {
    val num     = scala.io.StdIn.readInt
    val factors = scala.io.StdIn.readLine.split(" ").map{_.toInt}.sorted
    println(factors.last - factors.head)
  }
}
