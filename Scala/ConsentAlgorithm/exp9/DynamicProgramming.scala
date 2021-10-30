object DynamicProgramming {
    def main( args: Array[String] ): Unit = {
        val list = Map(
            "apple"  -> Array( 3, 5 ),
            "orange" -> Array( 2, 6 ),
            "banana" -> Array( 4, 7 )
        )

        val weight = 8

        dynamicProgramming( list, weight ).foreach { i => 
            print( i + ", ")
        }
        println()
    }

    def dynamicProgramming( list: Map[String, Array[Int]], max_weight: Int ): Array[String] = {
        val check_factor  = list.keys.toArray
        var grid          = Array.ofDim[Int]( check_factor.size, max_weight + 1 )
        var select_factor = Array.ofDim[Array[String]]( check_factor.size, max_weight + 1 )

        ( 0 until check_factor.size ).foreach { i => 
            val factor        = check_factor( i )
            val factor_weight = list( factor )( 0 )
            val factor_value  = list( factor )( 1 )

            ( 0 until max_weight + 1 ).foreach { j => 
                // select_factor の初期化
                select_factor( i )( j ) = Array()
            
                if( i >= 1 && grid( i )( j ) < grid( i - 1 )( j ) ) {
                    grid( i )( j )          = grid( i - 1 )( j ) 
                    select_factor( i )( j ) = select_factor( i - 1 )( j )
                }

                if( j >= factor_weight ) {
                    var selects = Array( factor ) 
                    var values  = factor_value
                    if( i >= 1 ) { 
                        values   += grid( i - 1 )( j - factor_weight )
                        selects ++= select_factor( i - 1 )( j - factor_weight )
                    }  

                    if( grid( i )( j ) < values ) { 
                        grid( i )( j )          = values
                        select_factor( i )( j ) = selects
                    }
                }
            }
        }

        println( "max value is > " + grid( check_factor.size - 1 )( max_weight ) )
        return select_factor( check_factor.size - 1 )( max_weight )
    }
}