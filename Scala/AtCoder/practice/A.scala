object A {
  def main(args: Array[String]): Unit = {
    val a    = io.StdIn.readInt()
    val nums = io.StdIn.readLine().split(" ")
    val str  = io.StdIn.readLine()
    val sum  = a + nums(0).toInt + nums(1).toInt
    println(sum + " " + str)
  }
}
