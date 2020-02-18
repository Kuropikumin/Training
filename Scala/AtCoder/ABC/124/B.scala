object B {
  def main(args: Array[String]): Unit = {
    val hotel_num         = io.StdIn.readInt
    val hotel_height      = io.StdIn.readLine.split(" ").map{_.toInt}
    var total_can_see_sea = 0
    var max_height        = 0

    (0 until hotel_height.length).foreach { i =>
      if(hotel_height(i) >= max_height) {
        total_can_see_sea += 1
        max_height = hotel_height(i)
      }
    }
    println(total_can_see_sea)

  }
}
