object Main {
  def main(args: Array[String]): Unit = {
    val date = scala.io.StdIn.readInt
    print("Christmas")
    val diff_christmas_date = 25 - date
    for(i <- 0 until diff_christmas_date) {
      print(" Eve")
    }
    println("")
  }
}
