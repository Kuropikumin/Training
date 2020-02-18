object Main {
  def main(args: Array[String]): Unit = {
    val num     = scala.io.StdIn.readInt
    val factors = scala.io.StdIn.readLine.split(" ")
    var sum = 0

    factors.foreach({ i=>
      sum += countDivisibleBy2(i.toInt)
    })
    println(sum)
  }

  def countDivisibleBy2(input: Int): Int = {
    var num = input
    var count = 0
    while(num%2 == 0) {
      num   =  num/2
      count += 1
    }

    return count
  }
}
