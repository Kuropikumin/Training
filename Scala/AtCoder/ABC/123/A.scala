object A {
  def main(args: Array[String]): Unit = {
    val a = io.StdIn.readInt()
    val b = io.StdIn.readInt()
    val c = io.StdIn.readInt()
    val d = io.StdIn.readInt()
    val e = io.StdIn.readInt()
    val k = io.StdIn.readInt()

    if(e - a <= k) println("Yay!")
    else           println(":(")
  }
}
