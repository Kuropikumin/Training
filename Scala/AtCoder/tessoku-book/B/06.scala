import scala.collection.mutable.ArrayBuffer
object Main {
  def main(args: Array[String]): Unit = {
    val try_num = scala.io.StdIn.readInt()
    val results = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
    val total_hit_num  = ArrayBuffer.empty[Int]
    val total_miss_num = ArrayBuffer.empty[Int]

    ( 0 until results.length ).foreach{ i =>
      var hit  = 0
      var miss = 0
      if( i > 0 ) {
        hit  = total_hit_num( i - 1 )
        miss = total_miss_num( i - 1 )
      }
      
      if( results( i )  == 1 ) hit  += 1
      else                     miss += 1
      total_hit_num  += hit
      total_miss_num += miss
    }
    
    val question_num = scala.io.StdIn.readInt()
    ( 0 until question_num ).foreach{ i => 
      val Array( start, end ) = scala.io.StdIn.readLine.split( " " ).map{ _.toInt }
      var check_hit_num  = total_hit_num( end - 1 )
      var check_miss_num = total_miss_num( end - 1 )
      if( start > 1 ) {
        check_hit_num -= total_hit_num( start - 2 )
        check_miss_num -= total_miss_num( start - 2 )
      }

      var answer = "draw"
      if( check_hit_num > check_miss_num ) {
        answer = "win"
      }
      else if( check_hit_num < check_miss_num ) {
        answer = "lose"
      }

      println( answer )
    }
  }
}
