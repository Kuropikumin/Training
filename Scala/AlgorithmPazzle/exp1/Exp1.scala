object Exp1 {
  def main(args: Array[String]): Unit = {
    val peoples = 100
    var finish_comb = 0

    (0 to peoples).foreach { i =>
      (0 to i).foreach { j =>

        var rock_nums     = peoples - i
        var scissors_nums = i - j
        var paper_nums    = j

        if( isFinishGame( rock_nums, scissors_nums, paper_nums ) ) finish_comb += 1
      }
    }

    println(finish_comb)

  }

  def isFinishGame( rock_nums: Int, scissors_nums: Int, paper_nums: Int ): Boolean = {
    if( ( rock_nums     > scissors_nums && rock_nums     > paper_nums ) ||
        ( scissors_nums > rock_nums     && scissors_nums > paper_nums ) ||
        ( paper_nums    > rock_nums     && paper_nums    > scissors_nums )
      ) {
        return true
    }
    return false
  }
}
