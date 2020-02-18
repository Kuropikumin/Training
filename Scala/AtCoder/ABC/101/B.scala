object Main {
  def main(args: Array[String]): Unit = {
    val num  = scala.io.StdIn.readInt
    var snum = calcSnum(num)

    if(num%snum == 0) println("Yes")
    else              println("No")
  }

  def calcSnum(num: Int): Int = {
    if(num < 10) return num
    else         return num%10 + calcSnum(num/10)
  }
}
