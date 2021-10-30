object D {
    def main(args: Array[String]): Unit = {
        val Array( n, m ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
        val nums          = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
        var result        = Range( 1, m + 1 ).toArray

        ( 2 to 100 ).foreach { i =>
          
        }

        println( result.length )
        result.foreach { println( _ ) }

    }
}
