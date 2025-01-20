object PrintText {
  def main( args: Array[String] ): Unit = {
    printFile( "User.scala" )     
  }

  def withFile[A]( filename: String )( f: scala.io.Source => A ): A = {
    val s = scala.io.Source.fromFile( filename )
    try {
      f( s )
    } finally {
      s.close()
    }
  }

  def printFile( filename: String ): Unit = {
    withFile( filename )( { file =>
      file.getLines.foreach( println )
    } )
  }
}