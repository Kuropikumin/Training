object C {
  def main(args: Array[String]): Unit = {
    val tiles = io.StdIn.readLine().split("").filter(_ != "").map{_.toInt}

    var tiles01_change_num = 0
    var tiles10_change_num = 0

    (0 until tiles.length).foreach { i =>
      if(tiles(i) != i%2)            tiles01_change_num += 1
      else if(tiles(i) != (i + 1)%2) tiles10_change_num += 1
    }

    if(tiles01_change_num < tiles10_change_num) {
      println(tiles01_change_num)
    }
    else {
      println(tiles10_change_num)
    }
  }
}
