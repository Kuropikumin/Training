object A {
  def main(args: Array[String]): Unit = {
    val nums = io.StdIn.readLine.split(" ").map{_.toInt}
    if(500*nums(0) > nums(1)) println("Yes")
    else                      println("No")
  }
}
