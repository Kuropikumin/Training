object B {
  def main(args: Array[String]): Unit = {
    val str_len = io.StdIn.readInt
    val Array(str1, str2) = io.StdIn.readLine.split(" ")
    var ans_str = ""

    (0 until str_len).foreach{ i =>
      ans_str += str1(i).toString + str2(i)
    }
    println(ans_str)
  }
}
