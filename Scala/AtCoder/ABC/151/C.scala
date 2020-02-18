object C {
  def main(args: Array[String]): Unit = {
    val Array(problem_num, answer_num) = io.StdIn.readLine.split(" ").map{_.toInt}

    var count = 0
    var fail_count = 0
    var pass_problem = Vector.empty[Int]

    while(count < answer_num) {
      val Array(answer_num, pass_or_fail) = io.StdIn.readLine.split(" ")
      var check = true

      pass_problem.foreach { i=>
        if(i == answer_num.toInt) check = false
      }
      if(check) {
        if(pass_or_fail == "AC") pass_problem = pass_problem :+ answer_num.toInt
        else                     fail_count += 1
      }
      count += 1
    }

    println(pass_problem.length.toString + " " + fail_count.toString)
  }
}
