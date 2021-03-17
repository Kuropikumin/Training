// コンパイル方法： scalac ScalaApp.scala ChecksumAccumulator.scala
import ChecksumAccumulator.calculate
object ScalaApp extends App {
  for( season <- List( "fall", "winter", "sprint", "summer" ) )
    println( season + " : " + calculate( season ) )
}
