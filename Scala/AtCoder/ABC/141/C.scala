object C {
  def main(args: Array[String]): Unit = {
    val factors    = scala.io.StdIn.readLine.split(" ")
    val last_point = factors(1).toInt - factors(2).toInt

    var scores = Array.fill(factors(0).toInt)(last_point)

    println(last_point)
    var count = 1
    while(count <= factors(2).toInt) {
      var num = scala.io.StdIn.readInt
      scores(num - 1) += 1
      count += 1
    }

    scores.foreach{ i =>
      if(i > 0) println("Yes")
      else      println("No")
    }
  }
}
