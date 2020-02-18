object Main {
  def main(args: Array[String]): Unit = {
    val str = scala.io.StdIn.readLine
    var flg = true
    var upper_count = 0

    if(str.head != 'A') flg = false

    for( i <- 1 to str.length - 1) {
      if( str(i).isUpper ) {
        if( i == 1 || i == str.length - 1 || str(i) != 'C') {
          flg = false
        }
        upper_count += 1
      }
    }

    if(upper_count != 1) flg = false


    if(flg) println("AC")
    else    println("WA")

  }
}
