object A {
  def main(args: Array[String]): Unit = {
    val input = scala.io.StdIn.readLine.split(" ").map{_.toInt}
    val sum   = input(0) + input(1)

    if(sum%2 == 0) println(sum/2)
    else           println("IMPOSSIBLE")

  }
}
