object Main {
  def main(args: Array[String]): Unit = {
    val str    = scala.io.StdIn.readLine
    val answer = scala.io.StdIn.readLine
    var flg    = false

    var check_str = str
    for(i <- 0 until str.length) {
      check_str = check_str.tail + check_str.head
      if(check_str == answer) flg = true
    }

    if(flg) {
      println("Yes")
    }
    else {
      println("No")
    }

  }
}
