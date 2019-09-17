object Main {
  def main(args: Array[String]): Unit = {
    val factors = scala.io.StdIn.readLine.split(" ")
    var answer  = factors(1).toInt * Math.pow(100, factors(0).toInt).toInt
    if (factors(1).toInt == 100) answer += Math.pow(100, factors(0).toInt).toInt
    println(answer)
  }
}
