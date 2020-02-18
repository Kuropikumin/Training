object A {
  def main(args: Array[String]): Unit = {
    val cells       = io.StdIn.readLine().split(" ").map{_.toInt}
    val brack_cells = io.StdIn.readLine().split(" ").map{_.toInt}
    println((cells(0) - brack_cells(0))*(cells(1) - brack_cells(1)))
  }
}
