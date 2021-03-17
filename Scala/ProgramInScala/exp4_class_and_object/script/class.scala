class Test {
  var sum = 0
}

class Test2 {
  private var sum = 0
}

val test1 = new Test
val test2 = new Test
test1.sum = 3
test2.sum = 5

println( "test1.sum = " + test1.sum )
println( "test2.sum = " + test2.sum )

val test3 = new Test2
// ここでエラー発生
// Test2 の sum は private フィールドなので外部からの操作不可
// test3.sum = 10
