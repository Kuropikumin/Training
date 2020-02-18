object C {
  def main(args: Array[String]): Unit = {
    val towns           = scala.io.StdIn.readInt()
    var enemys          = scala.io.StdIn.readLine.split(" ").map{_.toInt}
    val killable_enemys = scala.io.StdIn.readLine.split(" ").map{_.toInt}

    var sum_kill_enemys = 0

    (0 until killable_enemys.length).foreach{ i =>
      
    }
    println(sum_kill_enemys)
  }
}
