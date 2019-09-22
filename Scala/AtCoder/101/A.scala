object Main {
  def main(args: Array[String]): Unit = {
    val factors = scala.io.StdIn.readLine.split("")
    var sum = 0

    factors.foreach({ i =>
      if     (i == "+") sum += 1
      else if(i == "-") sum -= 1
    })

    println(sum)
  }
}
