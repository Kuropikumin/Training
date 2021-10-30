class Ruler
  def initialize( length )
    @length = length
  end

  def to_s
    '=' * @length
  end

  def inspect
    "Ruler( length: #{ @length } )"
  end
end

ruler = Ruler.new( 20 )

puts ruler
p ruler
