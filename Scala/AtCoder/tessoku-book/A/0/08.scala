import scala.collection.mutable.ArrayBuffer
object Main {
  def main(args: Array[String]): Unit = {
    val Array( height, width ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    val x_list = Array.fill( height, width )( 0 )
    ( 0 until height ).foreach{ i => 
      val list = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
      ( 0 until width ).foreach{ j =>
        x_list( i )( j ) = list( j )
      }
    }

    var z_list = Array.fill( height + 1, width + 1 )( 0 )
    ( 1 to height ).foreach{ y =>
      ( 1 to width ).foreach{ x =>
        z_list( y )( x ) = z_list( y )( x - 1 ) + x_list( y - 1 )( x - 1 )
      }
    }
    ( 1 to width ).foreach{ x =>
      ( 1 to height ).foreach{ y => 
        z_list( y )( x ) = z_list( y - 1 )( x ) + z_list( y )( x )        
      }
    }

    val question_num = scala.io.StdIn.readInt
    ( 0 until question_num ).foreach{ i =>
      val Array( a, b, c, d ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
      val answer = z_list( c )( d ) + z_list( a - 1 )( b - 1 ) - z_list( a - 1 )( d ) - z_list( c )( b - 1 )
      println( answer )
    }
  }
}
