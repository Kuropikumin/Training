object B {
  def main( args: Array[String] ): Unit = {
    val base_num    = io.StdIn.readInt
    var count_total_people = Array.fill( 24 )( 0L )

    ( 0 until base_num ).foreach{ i =>
      val base_facts = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
      ( 0 until 9 ).foreach{ j =>
        count_total_people( ( 9 + j + base_facts( 1 ) )%24 ) += base_facts( 0 ).toLong
      }
    }

    println(count_total_people.max )
  }
}
