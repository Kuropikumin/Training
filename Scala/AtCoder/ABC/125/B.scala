object B {
  def main(args: Array[String]): Unit = {
    val jewelry_nums   = io.StdIn.readInt
    val jewelry_values = io.StdIn.readLine.split(" ").map{_.toInt}
    var jewelry_costs  = io.StdIn.readLine.split(" ").map{_.toInt}
    var max_profits    = 0

    (0 until jewelry_nums).foreach { i =>
      val profit = jewelry_values(i) - jewelry_costs(i)
      if(profit > 0) {
        max_profits += profit
      }
    }
    println(max_profits)

  }
}
