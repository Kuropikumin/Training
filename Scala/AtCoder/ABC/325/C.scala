object C {
  def main( args: Array[String] ): Unit = {
    val Array( h, w ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    var fields = Array.ofDim[String]( h, w )

    ( 0 until h ).foreach{ i =>
      val line = scala.io.StdIn.readLine.split( "" )
      ( 0 until w ).foreach{ j =>
        fields( i )( j ) = line( j )
      }
    }

    var count = 0
    ( 0 until h ).foreach{ i =>
      ( 0 until w ).foreach{ j =>
        if( fields( i )( j ) == "#" ) {
          count += 1
          findLinking( fields, i, j, h, w )
        }
      }
    }

    println( count )
  }

  def findLinking( fields: Array[Array[String]], start_h: Int, start_w: Int, max_h: Int, max_w: Int ): Unit = {
    fields( start_h )( start_w ) = "."
    ( -1 to 1 ).foreach{ move_h =>
      ( -1 to 1 ).foreach{ move_w =>
        val check_h = start_h + move_h
        val check_w = start_w + move_w

        if( ( 0 <= check_h && check_h < max_h ) &&
            ( 0 <= check_w && check_w < max_w )
          ) {
          if( fields( check_h )( check_w ) == "#" ) {
            findLinking( fields, check_h, check_w, max_h, max_w )
          }
        }
      }
    }
  }
}