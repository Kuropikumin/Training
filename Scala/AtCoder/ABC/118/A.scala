object Main {
  def main(args: Array[String]): Unit = {
    var nums = scala.io.StdIn.readLine.split(" ").map{_.toInt}
    if(nums(1)%nums(0) == 0) {
      println(nums(0) + nums(1))
    }
    else {
      println(nums(1) - nums(0))
    }
  }
}
