object Main {
  def main( args: Array[String] ): Unit = {
    // var stack = scala.collection.mutable.Stack[Long]()
    var stack = new MyLongStack()
    val order = scala.io.StdIn.readLine.split( " " )
    var result = 0L

    order.foreach{ i =>
      var result = 0L
      i match {
        case "+" => result = stack.pop().toLong  + stack.pop().toLong
        case "-" => result = -stack.pop().toLong + stack.pop().toLong
        case "*" => result = stack.pop().toLong  * stack.pop().toLong 
        case _   => result = i.toLong 
      }
      stack.push( result )
    }
    println( stack.pop )
  }
}

class MyLongStack {
  var list = Array[Long]()
  def push( n: Long ): Unit = {
    list :+= n
  }
  def pop(): Long = {
    val n = list.last
    list = list.init
    return n
  }
}