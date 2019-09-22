object Main {
  def main(args: Array[String]): Unit = {
    val factors = scala.io.StdIn.readLine.split(" ").map{_.toInt}
    var answer = (factors(0) - 1)/(factors(1) - 1)

    if((factors(0) - 1)%(factors(1) - 1) == 0) println(answer)
    else                                       println(answer + 1)
  }
}
