println( " 1 == 2 = " + ( 1 == 2 ) + " : " + ( 1 == 2 ).getClass )
println( " 1 != 2 = " + ( 1 != 2 ) + " : " + ( 1 != 2 ).getClass )
println( " 2 == 2 = " + ( 2 == 2 ) + " : " + ( 2 == 2 ).getClass )

println( " List( 1, 2, 3 ) == List( 1, 2, 3 ) = " +
         ( List( 1, 2, 3 ) == List( 1, 2, 3 ) ) + " : " +
         ( List( 1, 2, 3 ) == List( 1, 2, 3 ) ).getClass )
println( " List( 1, 2, 3 ) == List( 1, 2, 4 ) = " +
         ( List( 1, 2, 3 ) == List( 1, 2, 4 ) ) + " : " +
         ( List( 1, 2, 3 ) == List( 1, 2, 4 ) ).getClass )
println( " List( 1, 2, 3 ) == Array( 1, 2, 3 ) = " +
         ( List( 1, 2, 3 ) == Array( 1, 2, 3 ) ) + " : " +
         ( List( 1, 2, 3 ) == Array( 1, 2, 3 ) ).getClass )

println( " 1 == 1.0 = "                        + ( 1 == 1.0 )                    + " : " + ( 1 == 1.0 ).getClass )
println( " 1 == 'a' = "                        + ( 1 == 'a' )                    + " : " + ( 1 == 'a' ).getClass )
println( " null == 1 = "                       + ( null == 1 )                   + " : " + ( null == 1 ).getClass )
println( "( \"he\" + \"llo\" ) == \"hello\" = " + ( ( "he" + "llo" ) == "hello" ) + " : " + ( ( "he" + "llo" ) == "hello" ).getClass )
