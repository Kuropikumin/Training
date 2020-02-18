object Main {
  def main(args: Array[String]): Unit = {
    val buy_num    = scala.io.StdIn.readInt
    var max_price  = 0
    var sum        = 0

    for(i <- 0 until buy_num) {
      val price = scala.io.StdIn.readInt
      sum += price
      if(max_price < price) max_price = price
    }

    println(sum - max_price/2)
  }
}
