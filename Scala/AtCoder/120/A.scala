object A {
  def main(args: Array[String]): Unit = {
    val nums = io.StdIn.readLine().split(" ").map{_.toInt}
    val count_of_listen = nums(1)/nums(0)
    if(nums(2) < count_of_listen) {
      println(nums(2))
    }
    else {
      println(count_of_listen)
    }
  }
}
