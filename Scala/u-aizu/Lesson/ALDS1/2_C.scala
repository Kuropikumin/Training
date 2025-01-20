object Main {
  def main( args: Array[String] ): Unit = {
    val list_length = scala.io.StdIn.readInt
    val list        = scala.io.StdIn.readLine.split( " " )

    val bubble_list = bubbleSort( list )
    println( bubble_list.mkString( " " ) )
    if( stableCheck( bubble_list, list ) ) {
      println( "Stable" )
    }
    else {
      println( "Not stable" )
    }

    val selection_list = selectionSort( list )
    println( selection_list.mkString( " " ) )
    if( stableCheck( selection_list, list ) ) {
      println( "Stable" )
    }
    else {
      println( "Not stable" )
    }
  }

  def bubbleSort( list: Array[String] ): Array[String] = {
    var result_list = list.clone()

    ( 0 until result_list.length ).foreach{ i =>
      ( i to 1 by -1 ).foreach{ j =>
        val j1_num = result_list( j )( 1 ).toInt
        val j2_num = result_list( j - 1 )( 1 ).toInt
        if( j1_num < j2_num ) {
          val tmp = result_list( j )
          result_list( j ) = result_list( j - 1 )
          result_list( j - 1 ) = tmp
        }
      }
    }

    return result_list
  }

  def selectionSort( list: Array[String] ): Array[String]  = {
    var result_list = list.clone()

    ( 0 until result_list.length ).foreach{ i =>
      var change_element = i
      ( i until result_list.length ).foreach{ j =>
        if( result_list( j )( 1 ).toInt < result_list( change_element )( 1 ).toInt  ) {
          change_element = j
        }
      }
      val tmp = result_list( i )
      result_list( i ) = result_list( change_element )
      result_list( change_element ) = tmp
    }

    return result_list
  }

  def stableCheck( list1: Array[String], list2: Array[String] ): Boolean = {
    var flag = true

    ( 0 until list1.length - 1 ).foreach{ i =>
      if( list1( i )( 1 ) == list1( i + 1 )( 1 ) ) {
        if( list2.indexOf( list1( i + 1 ) ) < list2.indexOf( list1( i ) ) ) {
          flag = false
        }  
      }
    }

    return flag
  }
}