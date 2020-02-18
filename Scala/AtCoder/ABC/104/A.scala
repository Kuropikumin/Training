object Main {
  def main(args: Array[String]): Unit = {
    val rate = scala.io.StdIn.readInt

    if(rate < 1200)      println("ABC")
    else if(rate < 2800) println("ARC")
    else                 println("AGC")
  }
}
