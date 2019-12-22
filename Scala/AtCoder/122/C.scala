object C {
  def main(args: Array[String]): Unit = {
    val Array(str_length, check_str_nums) = io.StdIn.readLine.split(" ").map{_.toInt}
    val input_str = io.StdIn.readLine()
    var ac_head = Vector.empty[Tuple2[Int, Int]]
    var total_ac_count = 0

    (0 until input_str.length - 1).foreach{ i =>
      if(input_str(i) == 'A' && input_str(i + 1) == 'C') {
        total_ac_count += 1
        ac_head = ac_head :+ (i, total_ac_count)
      }
    }
    ac_head.foreach{ i =>
      println(i)
    }

    (0 until check_str_nums).foreach{ i =>
      var (start_ac_count, end_ac_count) = (0, 0)
      ac_head.foreach { j =>
        if(

      println(ac_count)
    }
  }
}
