object B {
  def main(args: Array[String]): Unit = {
    var max_acgt_length = 0
    val input_str = io.StdIn.readLine()

    (0 until input_str.length).foreach{ i =>
      var acgt_length = 0
      var flag        = true

      while(flag) {
        if("ACGT".contains(input_str(i + acgt_length))) {
          acgt_length += 1
        }
        else {
          flag = false
        }

        if(i + acgt_length >= input_str.length) {
          flag = false
        }
      }
      if(acgt_length > max_acgt_length) max_acgt_length = acgt_length
    }
    println(max_acgt_length)
  }
}
