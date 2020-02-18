object B {
  def main(args: Array[String]): Unit = {
    val Array(t_cookie, a_cookie, required_cookie) = io.StdIn.readLine.split(" ").map{_.toLong}
    var t_after_cookie = 0L
    var a_after_cookie = 0L
    if(t_cookie + a_cookie >= required_cookie) {
      t_after_cookie = if (t_cookie >= required_cookie) t_cookie - required_cookie else 0
      a_after_cookie = if (t_after_cookie > 0)          a_cookie                   else t_cookie + a_cookie - required_cookie
    }
    else {
      t_after_cookie = 0
      a_after_cookie = 0
    }

    println(t_after_cookie.toString + " " + a_after_cookie.toString)
  }
}
