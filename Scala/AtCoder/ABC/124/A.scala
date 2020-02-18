object A {
  def main(args: Array[String]): Unit = {
    var button_size = io.StdIn.readLine().split(" ").map{_.toInt}
    var total_coin  = 0

    (0 until 2).foreach { i =>
      if(button_size(0) > button_size(1)) {
        total_coin += button_size(0)
        button_size(0) -= 1
      }
      else {
        total_coin += button_size(1)
        button_size(1) -= 1
      }
    }
    println(total_coin)
  }
}
