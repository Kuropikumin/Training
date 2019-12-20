object Main {
  def main(args: Array[String]): Unit = {
    val age = scala.io.StdIn.readInt
    if(age == 3 || age == 5 || age == 7) {
      println("YES")
    }
    else {
      println("NO")
    }
  }
}
