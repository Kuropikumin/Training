object E {
  def main(args: Array[String]): Unit = {
    var input_num = io.StdIn.readLong()

    if(input_num%2 == 1) println(0)
    else {
      var total_five = 0L
      while(input_num > 5) {
        total_five += input_num/10L
        input_num  = input_num/5L
      }
      println(total_five)
    }
  }
}
