object B {
  def main(args: Array[String]): Unit = {
    val steps = scala.io.StdIn.readLine.split("")
    var flag  = true
    var count = 0

    steps.foreach({ i =>
      count += 1
      if(count%2 == 0) {
        if( i.equals("R")) flag = false
      }
      else {
        if( i.equals("L")) flag = false
      }
      println(count + " : " + i)
    })

    if(flag) println("Yes") else println("No")
  }
}
