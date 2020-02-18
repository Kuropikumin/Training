object Main {
  def main(args: Array[String]): Unit = {
    val factors = scala.io.StdIn.readLine.split(" ").map{_.toInt}
    println(factors(0).toInt + factors(1).toInt/2)
  }
}
