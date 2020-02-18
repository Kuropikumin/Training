object B {
  def main(args: Array[String]): Unit = {
    var cuisine_list = Vector.empty[Int]
    cuisine_list = cuisine_list :+ io.StdIn.readInt()
    cuisine_list = cuisine_list :+ io.StdIn.readInt()
    cuisine_list = cuisine_list :+ io.StdIn.readInt()
    cuisine_list = cuisine_list :+ io.StdIn.readInt()
    cuisine_list = cuisine_list :+ io.StdIn.readInt()
    var sum_time      = 0
    var min_last_time = 9

    (0 until cuisine_list.length).foreach { i =>
      val last_time = cuisine_list(i)%10
      if(last_time < min_last_time && last_time != 0) min_last_time = last_time
      sum_time += (cuisine_list(i)/10.0 + 0.9).toInt*10
      println(cuisine_list(i).toString + " > " + last_time + " : " + min_last_time)
    }
    println(sum_time - 10 + min_last_time)

  }
}
