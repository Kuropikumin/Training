object C {
  def main(args: Array[String]): Unit = {
    val num        = io.StdIn.readInt
    var prime_nums = Vector.empty[Int]

    (2 to num).foreach { i =>
      var flag = true
      (2 to Math.sqrt(i).toInt).foreach { j =>
        if(i%j == 0) flag = false
      }

      if(flag) prime_nums = prime_nums :+ i
    }

    var prime_flag = false
    var next_num = num

    if(prime_nums.last != num) {
      while(!prime_flag) {
        next_num += 1
        var flag = false
        prime_nums.foreach { i =>
          if(next_num%i == 0) flag = true
        }

        if(!flag) prime_flag = true
      }
    }

    println(next_num)
  }
}
