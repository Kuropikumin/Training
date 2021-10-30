def printMultiTable() {
  var i = 1
  while( i <= 10 ) {
    var j = 1
    while( j <= 10 ) {
      val prod = ( i*j ).toString
      var k    = prod.length
      // scope is i, j, prod, k
      while( k < 4 ) {
        print( " " )
        k += 1
      }
      print( prod )
      j += 1
    }
    // scope is i, j
    println()
    i += 1
  }
  // scope is i
}

printMultiTable()
