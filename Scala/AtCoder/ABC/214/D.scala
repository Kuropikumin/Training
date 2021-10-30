object D {
  def main(args: Array[String]): Unit = {
    val Array(heigth, width) = io.StdIn.readLine.split(" ").map{_.toInt}

    var map = Vector.empty[String]

    var count = 0
    var max_depth = 0

    while(count < height) {
      map = map :+ io.StdIn.readLine
    }

    (0 until height).foreach { i =>
      (0 until width).foreach { j =>
        i
      }
    }
  }

  def maxDFS(height: Int, width: Int): Int = {
  }

  def DFS(height: Int, width: Int, count: Int): Unit = {
  }
}
