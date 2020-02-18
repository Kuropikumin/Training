object Main {
  def main(args: Array[String]): Unit = {
    val factor_num = scala.io.StdIn.readInt
    val factors    = scala.io.StdIn.readLine.split(" ").map{_.toInt}.sorted
    var sum        = 0

    for(i <- 0 until (factors.length - 1)) {
      sum += factors(i)
    }

    if(sum > factors.last) println("Yes")
    else                   println("No")
  }
}
