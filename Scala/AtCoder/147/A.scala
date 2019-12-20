object A {
  def main(args: Array[String]): Unit = {
    val nums = io.StdIn.readLine().split(" ").map{_.toInt}
    val sum  = nums(0) + nums(1) + nums(2)
    if(sum < 22) println("win")
    else         println("burst")
  }
}
