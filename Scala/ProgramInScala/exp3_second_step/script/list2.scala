val list1 = List( "hoge", "fuga", "piyo" )
val list2 = "mytest" :: "twest" :: "hogefugapiyo" :: Nil

print( "list1 is > " )
list1.foreach( s => print( s + " : " ) )
println( "" )

print( "list2 is > " )
list2.foreach( s => print( s + " : " ) )
println( "" )

println( "list1 :: list2 is "  + ( list1 :: list2 ) )
println( "list1 ::: list2 is " + ( list1 ::: list2 ) )

println( "list1 ::: list2 filter 4 string length is > " + ( list1 ::: list2 ).filter( _.length == 4 ) )
