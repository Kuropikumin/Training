object C {
  def main(args: Array[String]): Unit = {
    val total_people = io.StdIn.readLong()
    var min_move_people_onetime = 1000000000000000L
    var min_move_people_num     = 1

    (0 until 5).foreach { i =>
      val input = io.StdIn.readLong()
      if (input < min_move_people_onetime) {
        min_move_people_onetime = input
        min_move_people_num = i
      }
    }
    println(Math.ceil(total_people/min_move_people_onetime.toDouble) + 4L)

  }
}
