val firstArg = if( args.length > 0 ) args( 0 ) else ""
val match_food = firstArg match {
  case "salt"  => "pepper"
  case "chips" => "salsa"
  case "eggs"  => "bacon"
  case _       => "fuf?"
}

println( match_food )
