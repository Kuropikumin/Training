object C {
  def main(args: Array[String]): Unit = {
    val factors      = io.StdIn.readLine().split(" ").map{_.toInt}
    var store_info   = Vector.empty[Vector[Int]]
    var total_fee    = 0l
    var purchase_num = 0

    (0 until factors(0)).foreach { i =>
      store_info = store_info :+ io.StdIn.readLine().split(" ").map{_.toInt}.toVector
    }

    store_info = store_info.sortWith(_(0) < _(0))

    (0 until factors(0)).foreach { i =>
      var buy_num = 0
      if(purchase_num >= factors(1)) buy_num = 0
      else if(purchase_num + store_info(i)(1) >= factors(1)) buy_num = factors(1) - purchase_num
      else buy_num = store_info(i)(1)

      total_fee    += (store_info(i)(0).toLong*buy_num)
      purchase_num += buy_num
    }
    println(total_fee)
  }
}
