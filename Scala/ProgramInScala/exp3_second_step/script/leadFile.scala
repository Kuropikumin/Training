if( args.length > 0 ) {
  for( line <- scala.io.Source.fromFile( args( 0 ) ).getLines() ) {
    println( line.length + " " + line )
  }
}
else {
  Console.err.println( "Usage: leadFile.scala <FILENAME> ... " )
}
