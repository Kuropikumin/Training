object B {
  def main(args: Array[String]): Unit = {
    val steps = scala.io.StdIn.readLine
    var flag  = true

    (0 until steps.length).foreach({ i =>
      if((i + 1)%2 == 0) {
        if( steps(i).equals("R")) flag = false
      }
      else {
        if( steps(i).equals("L")) flag = false
      }
    })

    if(flag) println("Yes") else println("No")
  }
}
