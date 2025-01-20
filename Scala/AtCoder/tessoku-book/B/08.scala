import scala.collection.mutable.ArrayBuffer
object Main {
  def main(args: Array[String]): Unit = {
    val x_max = 1500
    val y_max = 1500
    val point_num  = scala.io.StdIn.readInt
    val point_list = Array.fill( point_num, 2 )( 0 )
    ( 0 until point_num ).foreach{ i =>
      point_list( i ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    }

    val z_list = Array.fill( y_max + 1, x_max + 1 )( 0 )
    ( 0 until point_num ).foreach{ i =>
      val Array( y, x ) = point_list( i )
      z_list( y )( x ) += 1
    }
    ( 1 to y_max ).foreach{ y =>
      ( 1 to x_max ).foreach{ x =>
        z_list( y )( x ) += z_list( y )( x - 1 )
      }
    }
    ( 1 to x_max ).foreach{ x =>
      ( 1 to y_max ).foreach{ y => 
        z_list( y )( x ) += z_list( y - 1 )( x )        
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
