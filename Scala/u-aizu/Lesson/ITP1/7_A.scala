object Main {
  def main(args: Array[String]): Unit = {
    var continue_flag = true

    while( continue_flag ) {
      val Array( intermediate, term_end, make_up ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
      
      if( intermediate == -1 && term_end == -1 && make_up == -1 ) continue_flag = false
      else                                                        println( calcGrades( intermediate, term_end, make_up ) )

    }
  }
  
  def calcGrades( i: Int, t: Int, m: Int ): String = {
    if( i == -1 || t == -1 ) return "F"
    else {
      val sum = i + t
      sum match {
        case sum if sum >= 80 => return "A"
        case sum if sum >= 65 => return "B"
        case sum if sum >= 50 => return "C"
        case sum if sum >= 30 => {
          if( m >= 50 ) return "C"
          else          return "D"
        }
        case _ => return "F"
      }
    }
  }
}