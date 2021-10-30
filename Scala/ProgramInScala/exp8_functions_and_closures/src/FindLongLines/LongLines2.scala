import scala.io.Source
object LongLines {
  def processFile( filename: String, width: Int ): Unit = {
    val source = Source.fromFile( filename )
    for( line <- source.getLines() ) processLine( line )
    def processLine( line: String ): Unit = {
      if( line.length > width ) println( filename + " : " + line.trim )
    }
  }
}
