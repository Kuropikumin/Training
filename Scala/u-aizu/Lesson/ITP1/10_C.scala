object Main {
  def main( args: Array[String] ): Unit = {
    var continue_flag = true

    while( continue_flag ) {
      var scores_num = scala.io.StdIn.readInt
      if( scores_num == 0 ) continue_flag = false
      else {
        val scores = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
        println( Math.sqrt( calcDispersion( scores ) ) )
      }
    }   
  }

  def calcDispersion( scores: Array[Int] ): Double = {
    val ave = scores.sum/scores.length.toDouble
    var dispersion = 0d
    scores.foreach{ i =>
      dispersion += Math.pow( ( i.toDouble - ave ), 2 )
    }

    return dispersion/scores.length
  }
}