import scala.collection.mutable.ArrayBuffer
object Main {
  def main(args: Array[String]): Unit = {
    val num = scala.io.StdIn.readInt()
    val y_max = 1500
    val x_max = 1500
    val field = Array.fill( y_max + 9, x_max + 9 )( 0 )
    ( 0 until num ).foreach{ i => 
      val Array( a, b, c, d ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
      field( a )( b ) += 1
      field( c )( d ) += 1
      field( c )( b ) -= 1
      field( a )( d ) -= 1
    }

    ( 0 to y_max ).foreach{ y =>
      ( 0 to x_max ).foreach{ x =>
        field( y )( x ) += field( y )( x - 1 )
      }
    }

    ( 0 to y_max ).foreach{ y =>
      ( 0 to x_max ).foreach{ x => 
        field( y )( x ) += field( y - 1 )( x )        
      }
    }

    var area = 0
    ( 0 to y_max ).foreach{ y =>
      ( 0 to x_max ).foreach{ x =>
        if( field( y )( x ) >= 1 ){
          // if( x == 0 || y == 0 ) println( "( x, y ) = ( " + x + ", " + y + " )" )
          area += 1
        }
      }
    }

    println( area )
  }
}
