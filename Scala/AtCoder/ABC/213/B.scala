object B {
  def main( args: Array[String] ): Unit = {
    val nums        = io.StdIn.readInt
    val scores      = io.StdIn.readLine.split( " " ).map{ _.toLong }
    val scores_sort = scores.sorted

    var booby_score = scores_sort( scores_sort.length - 2 )
    var booby_num   = scores.indexOf( booby_score ) + 1

    println( booby_num )
  }
}
