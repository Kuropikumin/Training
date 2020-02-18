object D {
  def main(args: Array[String]): Unit = {
    val brick_num = io.StdIn.readInt
    val factors   = io.StdIn.readLine.split(" ").map{_.toInt}
    var num_of_bricks_destroyed = 0

    var check_num = 1
    factors.foreach{ i =>
      if(check_num == i) {
        check_num += 1
      }
      else {
        num_of_bricks_destroyed += 1
      }
    }
    if(check_num == 1) println(-1)
    else               println(num_of_bricks_destroyed)
  }
}
