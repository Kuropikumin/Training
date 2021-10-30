object C {
  def main( args: Array[String] ): Unit = {
    val new_index   = scala.io.StdIn.readLine
    val people_num  = scala.io.StdIn.readInt
    var people_name = Array.empty[String]

    ( 0 until people_num ).foreach{ i =>
      people_name :+= scala.io.StdIn.readLine
    }

    mySort( people_name, index = new_index ).foreach{ i =>
      println( i )
    }
  }

  def mySort( list: Array[String], index: String ): Array[String] = {
    var index_list = Map.empty[String, Int]
    ( 0 until index.length ).foreach{ i =>
      index_list ++= Map( index( i ).toString -> i )
    }

    return list.sortWith( ( v1, v2 ) => checkSort( v1, v2, index_list ) )
  }

  def checkSort( a: String, b: String, index: Map[String, Int] ): Boolean = {
    val check_length = if( a.length > b.length ) b.length else a.length
    ( 0 until check_length ).foreach{ i =>
      if( index( a( i ).toString ) < index( b( i ).toString ) )       return true
      else if ( index( a( i ).toString ) > index( b( i ).toString ) ) return false
    }
    return true
  }
}
