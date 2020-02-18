object A {
  def main(args: Array[String]): Unit = {
    val base = io.StdIn.readLine()

    if (base == "A") {
      println("T")
    }
    else if(base == "T") {
      println("A")
    }
    else if(base == "C") {
      println("G")
    }
    else {
      println("C")
    }
  }
}
