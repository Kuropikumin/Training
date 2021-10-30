object C {
  def main(args: Array[String]): Unit = {
    val Array(problem_num, answer_num) = io.StdIn.readLine.split(" ").map{_.toInt}

    var count = 0
    var problem = Vector.empty[Tuple2[Int, String]]

    while(count < answer_num) {
      val Array(ans_num, pass_or_fail) = io.StdIn.readLine.split(" ")
      problem = problem :+ (ans_num.toInt, pass_or_fail)
      count += 1
    }

    var check_num = 0
    var check = false
    var fail_count = 0
    var fail_each_count = 0
    var pass_count = 0
    problem.sorted.foreach { i =>
      if ( check_num != i._1 ) {
        check_num = i._1
        check = false
        fail_each_count = 0
      }

      if(!check) {
        if(i._2 == "AC") {
          pass_count += 1
          check = true
          fail_count += fail_each_count
        }
        else {
          fail_each_count += 1
        }
      }
    }
    println(pass_count.toString + " " + fail_count.toString)
  }
}
