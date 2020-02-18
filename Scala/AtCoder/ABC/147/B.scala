object B {
  def main(args: Array[String]): Unit = {
    val str = io.StdIn.readLine()
    var total_change_char = 0
    (0 until str.length/2).foreach { i =>
      if(str(i) != str(str.length - (1 + i))) total_change_char += 1
    }
    println(total_change_char)
  }
}
