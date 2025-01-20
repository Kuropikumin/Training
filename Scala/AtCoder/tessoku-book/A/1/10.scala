import scala.collection.mutable.ArrayBuffer
object Main {
  def main(args: Array[String]): Unit = {
    val Array( height, width, days ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    val field = Array.fill( height + 2, width + 2 )( 0 )
    ( 0 until days ).foreach{ i => 
      val Array( a, b, c, d ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
      field( a )( b ) += 1
      field( c + 1 )( d + 1 ) += 1
      field( c + 1 )( b ) -= 1
      field( a )( d + 1 ) -= 1
    }

    ( 1 to height ).foreach{ y =>
      ( 1 to width ).foreach{ x =>
        field( y )( x ) += field( y )( x - 1 )
      }
    }
    ( 1 to width ).foreach{ x =>
      ( 1 to height ).foreach{ y => 
        field( y )( x ) += field( y - 1 )( x )        
      }
    }
    ( 1 to height ).foreach{ y =>
      val print_row = field( y ).tail.init.mkString( " " )        
      println( print_row )
    }
  }
}
