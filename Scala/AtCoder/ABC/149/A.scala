object A {
  def main(args: Array[String]): Unit = {
    val strs = io.StdIn.readLine.split(" ")
    println(strs(1) + strs(0))
  }
}
