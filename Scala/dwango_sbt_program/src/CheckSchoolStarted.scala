object CheckSchoolStarted {
    def main( args: Array[String] ): Unit = {
        print( "確認したい年齢を入力してください > " )
        var age: Int = scala.io.StdIn.readLine.toInt
        var isSchoolStarted: Boolean = false

        if( age.getClass.toString != "int" || age < 0 || 100 < age ) {
            println( "正しい値を入力してください" )
        }
        else if( age <= 6 && !isSchoolStarted ) { println( "幼児です" ) }
        else { println( "幼児ではありません" ) }
    }
}