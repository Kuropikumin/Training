object A {
  def main(args: Array[String]): Unit = {
    var nums = io.StdIn.readLine().split(" ").map{_.toInt}
    var total_biscuits = (nums(2)/nums(0)).toInt*nums(1)

    println(total_biscuits)
  }
}
