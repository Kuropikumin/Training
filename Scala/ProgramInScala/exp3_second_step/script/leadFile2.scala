// 文字数の桁数を返す関数
def widthOfLength( s: String ) = s.length.toString.length

if( args.length > 0 ) {
  val lines       = scala.io.Source.fromFile( args( 0 ) ).getLines().toList
  val longestLine = lines.reduceLeft( ( a, b ) => if( a.length > b.length ) a else b )
  val maxWidth    = widthOfLength( longestLine )
  for( line <- lines ) {
    val numSpaces = maxWidth - widthOfLength( line )
    val padding   = " "*numSpaces
    println( padding + line.length + " | " + line )
  }
}
else {
  Console.err.println( "Usage: leadFile.scala <FILENAME> ... " )
}
