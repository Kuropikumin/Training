val treasureMap = scala.collection.mutable.Map[Int, String]()

treasureMap += ( 1 -> "Go to island." )
treasureMap += ( 2 -> "Find big X on ground." )
treasureMap += ( 3 -> "Dig." )

println( treasureMap )
println( treasureMap( 2 ) )

