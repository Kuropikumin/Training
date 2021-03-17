class ChecksumAccumulator {
  private var sum = 0
  def add( b: Byte ) { sum += b }
  def getSum(): Int = sum
  def checksum(): Int =  ~( sum & 0xFF ) + 1
}

val test = new ChecksumAccumulator()
println( "new test : test.sum is " + test.getSum() )

test.add( 10 )
println( "add 10 : test.sum is " + test.getSum() )

test.add( 5 )
println( "add 5 : test.sum is " + test.getSum() )

println( "checksum : " + test.checksum() )
