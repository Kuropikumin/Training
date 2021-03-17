object Single {
  val name = "single"

  def printMethod(): Unit = { println( "Ojbect Method!" ) }
}

class Single {
  var sum = 0

  def getSum(): Int = sum
  def addSum( num: Int ): Unit = { sum += num }
  def printMethod(): Unit = { println( "Class Method" ) }
}

Single.printMethod()
println( "test is " + Single.name )
val test = new Single()

test.addSum( 10 )
println( "test.getSum() is " + test.getSum() )
test.printMethod()

//val test2 = new Single() // ここでエラーとなる
