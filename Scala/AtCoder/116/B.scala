object Main {
  def main(args: Array[String]): Unit = {
    var count = 1
    var vec   = Vector[Int]()
    var flg   = false

    vec = scala.io.StdIn.readInt +: vec
    while(!flg) {
      val calc_num = calc(vec(0))

      if(vec.contains(calc_num)) flg = true
      else                       vec = calc_num +: vec

      count += 1
    }

    println(count)
  }

  def calc(num: Int): Int = {
    if(num%2 == 0) return num/2
    else           return 3*num + 1
  }
}
