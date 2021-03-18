def salt()   = { println( "salt!" );   false }
def pepper() = { println( "pepper!" ); true }

println( "salt() && pepper() is > " )
salt() && pepper()
println( "" )

println( "pepper() && salt() is > " )
pepper() && salt()

