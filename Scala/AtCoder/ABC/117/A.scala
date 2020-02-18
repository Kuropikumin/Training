object Main {
  def main(args: Array[String]): Unit = {
    var length = scala.io.StdIn.readLine.split(" ").map{_.toDouble}
    println(length(0)/length(1))
  }
}
