object Main {
  def main(args: Array[String]): Unit = {
    val num = scala.io.StdIn.readInt
    if(num%2 == 0) println(num)
    else           println(num*2)
  }
}
