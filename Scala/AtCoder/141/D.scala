object D {
  def main(args: Array[String]): Unit = {
    val factors = scala.io.StdIn.readLine.split(" ").map{_.toInt}
    var prices  = scala.io.StdIn.readLine.split(" ").map{_.toLong}.sorted

    var count = 1
    while(count <= factors(1).toInt) {
      prices(prices.length - 1) = (prices.last/2)
      prices = prices.sorted
      count += 1
    }

    var sum = 0l
    prices.foreach{ i =>
      sum += i
    }
    println(sum)
  }
}
