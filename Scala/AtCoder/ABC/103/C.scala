object Main {
  def main(args: Array[String]): Unit = {
    val fac_num = scala.io.StdIn.readInt
    val factors = scala.io.StdIn.readLine.split(" ").map{_.toInt}
    var answer  = 0

    factors.foreach({ i =>
      answer += i - 1
    })

    println(answer)

  }
}
