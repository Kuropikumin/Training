object Main {
  def main(args: Array[String]): Unit = {
    val piece_of_cakes = scala.io.StdIn.readLine.split(" ")
    if(piece_of_cakes(0).toInt <= 8 && piece_of_cakes(1).toInt <= 8) println("Yay!")
    else                                                             println(":(")
  }
}
