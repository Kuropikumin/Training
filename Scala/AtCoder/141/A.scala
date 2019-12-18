object A {
  def main(args: Array[String]): Unit = {
    val before_weather = scala.io.StdIn.readLine
    var weather = ""
    if      (before_weather == "Sunny")  weather = "Cloudy"
    else if (before_weather == "Cloudy") weather = "Rainy"
    else if (before_weather == "Rainy")  weather = "Sunny"

    println(weather)
  }
}
