class Rational( n: Int, d: Int ) {
  require( d != 0 )
  private val g: Int = gcd( n.abs, d.abs )
          val numer: Int = n/g
          val denom: Int = d/g

  override def toString = numer.toString + " / " + denom.toString

  def this( n: Int ) = this( n, 1 )

  def + ( that: Rational ): Rational = {
    new Rational( numer*that.denom + denom*that.numer, denom*that.denom )
  }

  def + ( n: Int ): Rational = {
    new Rational( numer + denom*n, denom )
  }

  def - ( that: Rational ): Rational = {
    new Rational( numer*that.denom - denom*that.numer, denom*that.denom )
  }

  def - ( n: Int ): Rational = {
    new Rational( numer - denom*n, denom )
  }

  def * ( that: Rational ): Rational = {
    new Rational( numer*that.numer, denom*that.denom )
  }

  def * ( n: Int ): Rational = {
    new Rational( numer*n, denom )
  }

  def / ( that: Rational ): Rational = {
    new Rational( numer*that.denom, denom*that.numer )
  }

  def / ( n: Int ): Rational = {
    new Rational( numer, denom*n )
  }

  def lessThan( that: Rational ): Boolean = {
    this.numer*that.denom < this.denom*that.numer
  }

  def max( that: Rational ): Rational = {
    if( this.lessThan( that ) ) that else this
  }

  private def gcd( a: Int, b: Int ): Int = {
    if( b == 0 ) a else gcd( b, a%b )
  }
}


