object C {
  def main(args: Array[String]): Unit = {
    val factors = io.StdIn.readLine.split(" ").map{_.toInt}
    val gcd = calcGcd(factors(0), factors(1))
    println(gcd)
    println(factors(0).toLong*factors(1)/gcd)
  }

  def calcGcd(num1: Int, num2: Int): Int = {
    var a = num1
    var b = num2
    if(a > b) {
      val tmp = a
      a = b
      b = tmp
    }
    var r = b%a

    while(r != 0) {
      b = a
      a = r
      r = b%a
    }
    return a
  }
}
