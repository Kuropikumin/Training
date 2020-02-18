object B {
  def main(args: Array[String]): Unit = {
    val num = io.StdIn.readInt
    val str = io.StdIn.readLine
    var count = 0

    (0 until num - 2).foreach { i =>
      if(str(i) == 'A') {
        if(str(i + 1) == 'B' && str(i + 2) == 'C') count += 1
      }
    }
    println(count)
  }
}
