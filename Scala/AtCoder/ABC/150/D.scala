object D {
  def main(args: Array[String]): Unit = {
    val factors = io.StdIn.readLine.split(" ").map{_.toLong}
    val nums    = io.StdIn.readLine.split(" ").map{_.toLong}

    var least_common_multiple = 1L

    nums.foreach { i =>
      least_common_multiple *= i/2L/calcGcd(least_common_multiple, i/2L)
    }

    var count = 0
    var flag  = true
    
    if (least_common_multiple%2 == 1) {
      while(flag) {
        val check_num = (2*count + 1)*least_common_multiple
        if(check_num <= factors(1)) count += 1
        else flag = false
      }
    }

    println(count)

  }

    def calcGcd(num1: Long, num2: Long): Long = {
    var a = num1
    var b = num2
    if(a > b) {
      val tmp = a
      a = b
      b = tmp
    }
    var r = b%a

    while(r != 0L) {
      b = a
      a = r
      r = b%a
    }
    return a
  }
}
