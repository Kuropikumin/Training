object Main {
  def main(args: Array[String]): Unit = {
    val facs_num = scala.io.StdIn.readInt
    val facs = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }

    var min = Int.MaxValue
    var max = Int.MinValue
    var sum = 0L

    facs.foreach { i => 
      if( min > i ) min = i
      if( max < i ) max = i
      sum += i.toLong
    }

    println( min + " " + max + " " + sum )
  }
}
